from Crypto.Cipher import AES
import binascii

def ctr_encrypt(key, plaintext):
    cipher = AES.new(binascii.unhexlify(key), AES.MODE_ECB)
    nonce = os.urandom(8)
    counter = 0

    encrypted_text = b""
    for i in range(0, len(plaintext), 16):
        block = nonce + counter.to_bytes(8, 'big')
        keystream = cipher.encrypt(block)
        plaintext_block = plaintext[i:i+16]
        encrypted_block = bytes([a ^ b for a, b in zip(keystream, plaintext_block)])
        encrypted_text += encrypted_block
        counter += 1

    ciphertext = binascii.hexlify(nonce + counter.to_bytes(8, 'big') + encrypted_text).decode()
    return ciphertext

def ctr_decrypt(key, ciphertext):
    cipher = AES.new(binascii.unhexlify(key), AES.MODE_ECB)
    nonce = binascii.unhexlify(ciphertext[:16])
    counter = int.from_bytes(binascii.unhexlify(ciphertext[16:32]), 'big')
    encrypted_text = binascii.unhexlify(ciphertext[32:])

    keystream = b""
    while len(keystream) < len(encrypted_text):
        block = nonce + counter.to_bytes(8, 'big')
        keystream += cipher.encrypt(block)
        counter += 1

    plaintext = bytes([a ^ b for a, b in zip(keystream, encrypted_text)])
    return plaintext.decode()

# Ciphertext 1
key1 = '36f18357be4dbd77f050515c73fcf9f2'
ciphertext1 = '69dda8455c7dd4254bf353b773304eec0ec7702330098ce7f7520d1cbbb20fc388d1b0adb5054dbd7370849dbf0b88d393f252e764f1f5f7ad97ef79d59ce29f5f51eeca32eabedd9afa9329'

plaintext1 = ctr_decrypt(key1, ciphertext1)
print(plaintext1)

# Ciphertext 2
key2 = '36f18357be4dbd77f050515c73fcf9f2'
ciphertext2 = '770b80259ec33beb2561358a9f2dc617e46218c0a53cbeca695ae45faa8952aa0e311bde9d4e01726d3184c34451'

plaintext2 = ctr_decrypt(key2, ciphertext2)
print(plaintext2)
