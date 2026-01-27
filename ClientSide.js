function checkCode() {
    const input = document.getElementById("code").value;
    const result = document.getElementById("result");

    if (input === "SummitGateAccess2026") {
        result.innerText = "Access granted: Summit{Client_Side_Logic_Is_Not_Security}";
    } else {
        result.innerText = "Access denied.";
    }
}
