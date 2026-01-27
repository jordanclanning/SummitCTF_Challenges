""" used python3 """

'EOF'
flag = b"Summit{runtime_memory_only}"
key = b"key123"
enc = [flag[i] ^ key[i % len(key)] for i in range(len(flag))]
print(enc)
EOF
