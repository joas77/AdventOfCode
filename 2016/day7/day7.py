import re

class IPv7:
    def __init__(self, addr):
        self._addr = addr
        self._regex = re.compile(r"\[\w+\]")

    def support_tls(self) -> bool:
        matches = self._regex.split(self._addr)
    
        print(matches)
        print(self.hypernet_seqs())
        return False
    
    def hypernet_seqs(self) -> list[str]:
        return [ self._rm_brackets(seq) for seq in self._regex.findall(self._addr) ]

    @staticmethod
    def _rm_brackets(sequence: str) ->str:
        return sequence.lstrip("[").rstrip("]")



if __name__ == "__main__":
    ipv7_addrs = [
        "abba[mnop]qrst",
        "abcd[bddb]xyyx",
        "aaaa[qwer]tyui",
        "ioxxoj[asdfgh]zxcvbn"
    ]

    for addr in ipv7_addrs:
        ipv7 = IPv7(addr)
        print(addr)
        if ipv7.support_tls():
            print(f"{addr} supports TLS")

        print("======")