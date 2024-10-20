import re

s = input("Enter statement: ")

# Regular expression for IPv4
ipv4Pattern = r'\b\d{1,3}(?:[.]\d{1,3}){3}\b'

# Regular expression for IPv6
ipv6Pattern = r'\b(?:[0-9a-fA-F]{1,4}:){1,7}[0-9a-fA-F]{1,4}|\b(?:[0-9a-fA-F]{1,4}:){1,7}:|::(?:[0-9a-fA-F]{1,4}:){1,6}[0-9a-fA-F]{1,4}\b'

ipv4Res = re.findall(ipv4Pattern, s)
ipv6Res = re.findall(ipv6Pattern, s)

if ipv4Res or ipv6Res:
    if ipv4Res:
        print("IPv4 address:", ipv4Res)
    if ipv6Res:
        print("IPv6 address:", ipv6Res)
else:
    print("No, the string does not have an IP address")