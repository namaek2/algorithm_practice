import binascii
output = "24 27 13 C6 C6 13 16 E6 47 F5 26 96 47 F5 46 27 13 26 26 C6 56 F5 C3 C3 F5 E3 E3 00".replace(" ", "")
output = binascii.unhexlify(output)


input = ""
for i in range(len(output)):
    for j in range(256):
        calc = ((16 * j) | (j >> 4)) % 256
        if calc == output[i]:
            input += chr(j)

print(input) #Br1ll1ant_bit_dr1bble_<<_>>