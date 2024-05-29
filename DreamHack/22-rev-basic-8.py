import binascii

output = "AC F3 0C 25 A3 10 B7 25 16 C6 B7 BC 07 25 02 D5 C6 11 07 C5 00".replace(" ", "")
output = binascii.unhexlify(output)
input = ""

for i in range(len(output)):
    for j in range(256):
        if (j * 251) & 255 == output[i]: #0xfb = -5 = 0b11111011
            input += chr(j)
            
print(input)