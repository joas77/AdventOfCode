import re

class IPv7:
    def __init__(self, addr):
        self._addr = addr
        self._regex = re.compile(r"\[\w+\]")

    def support_tls(self) -> bool:
        matches = self._regex.split(self._addr)
    
        abba_in_ip = False
        for m in matches:
            if self._contains_abba(m):
                # print(f"{m} contains a mirror pair")
                abba_in_ip = True
                break
        
        abba_in_hypernet = False
        for hs in self.hypernet_seqs():
            if self._contains_abba(hs):
                abba_in_hypernet = True
                break
        
        return abba_in_ip and not abba_in_hypernet
    
    def hypernet_seqs(self) -> list[str]:
        return [ self._rm_brackets(seq) for seq in self._regex.findall(self._addr) ]

    @staticmethod
    def _rm_brackets(sequence: str) ->str:
        return sequence.lstrip("[").rstrip("]")
    
    @staticmethod
    def _contains_abba(sequence: str) -> bool:
        """
        Returns true if there are any four character in sequence which consist of a
        pair of two different characters followed byt the reverse of that pair like xyyx
        @param: sequence: str
        """
        for i in range(len(sequence)):
            if sequence[i:i+2] == reverse_str(sequence[i+2:1+4]) and sequence[i] != sequence[i+1]:
                return True
            
        return False


def reverse_str(msg: str) -> str:
    return msg[::-1]

def get_ipv7_addresses():
    with open("input.txt") as f:
        for line in f.readlines():
            yield line.strip()

if __name__ == "__main__":
    ipv7_addrs = [
        "abba[mnop]qrst",
        "abcd[bddb]xyyx",
        "aaaa[qwer]tyui",
        "ioxxoj[asdfgh]zxcvbn"
    ]

    ipv7_addrs = get_ipv7_addresses()

    addr_tls_count = 0
    for addr in ipv7_addrs:
        ipv7 = IPv7(addr)
        if ipv7.support_tls():
            addr_tls_count += 1
            print(f"{addr} supports TLS")
            print("=============================================")

    #addr_tls_count = sum([ IPv7(addr).support_tls() for addr in ipv7_addrs])
    print(f"Count of IPv7 addresses that support TLS: {addr_tls_count}")