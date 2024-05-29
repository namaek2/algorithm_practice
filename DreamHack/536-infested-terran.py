import binascii

qword_4020 = "03 01 03 03 07 01 05 57 65 27 72 65 20 67 6F 6E 6E 61 20 62 65 20 72 69 63 68 3F 20 6E 65 76 65 72 2E 2E 2E"
qword_4020 = qword_4020.replace(" ", "")
qword_4020 = binascii.unhexlify(qword_4020)

qword_4140 = [0xCC, 0x0114, 0x0285, 0x032A, 0x05D1, 0x0632, 0x0736, 0x28DB, 0x5119, 0x607C, 0x8BAE, 0x9FCD, 0xA5CD, 0xB91D, 0xCECB, 0xE36B, 0xFB7B, 0x010F2F, 0x01154F, 0x012811, 0x013DC4, 0x0144E4, 0x015D62, 0x01745A, 0x01899F, 0x01B2A7, 0x01BFF1, 0x01C6B1, 0x01F0CD, 0x02074A, 0x021DE0, 0x0244EF, 0x0271E9, 0x027B9D, 0x0284C7, 0x029B3D]
#qword_4140 = qword_4140.replace(" ", "")
#qword_4140 = binascii.unhexlify(qword_4140)

input =""
for i in range(36) :
    a = 0
    v6=qword_4140[i]
    #for j in range (i) :
    if i > 0:
        v6 = v6 - qword_4140[i-1]
    
    #print(v6)
    a = v6 / qword_4020[i]
    input += chr(int(a))

print(input)
    