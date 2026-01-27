from scapy.all import *

# Base64-encoded flag: Summit{WarmCookie_Cookie_Exfil}
ENCODED_FLAG = b"; exfil=U3VtbWl0e1dhcm1Db29raWVfQ29va2llX0V4ZmlsfQ=="

INPUT_PCAP = "warmcookie_ctf.pcap"
OUTPUT_PCAP = "warmcookie_ctf_flagged.pcap"

pkts = rdpcap(INPUT_PCAP)
out = []
inserted = False

for p in pkts:
    if (
        not inserted
        and p.haslayer(IP)
        and p.haslayer(TCP)
        and p.haslayer(Raw)
        and p[IP].src == "10.8.15.133"
        and p[IP].dst == "72.5.43.29"
    ):
        payload = p[Raw].load

        # Look for raw HTTP POST with Cookie header
        if payload.startswith(b"POST ") and b"Cookie:" in payload:
            lines = payload.split(b"\r\n")

            for i, line in enumerate(lines):
                if line.startswith(b"Cookie:"):
                    lines[i] = line + ENCODED_FLAG
                    inserted = True
                    break

            p[Raw].load = b"\r\n".join(lines)

            # Recalculate checksums
            del p[IP].chksum
            del p[TCP].chksum

    out.append(p)

wrpcap(OUTPUT_PCAP, out)

if inserted:
    print("[+] Flag successfully injected into Cookie header")
else:
    print("[-] No suitable packet found; flag NOT injected")
