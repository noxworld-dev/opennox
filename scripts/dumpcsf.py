#!/usr/bin/env python3
import struct
import yaml

f = open('nox.csf', 'rb')
magic, version, num_labels, num_strings, _, lang = struct.unpack('<4sIIIII', f.read(0x18))

labels = {}

while True:
    magic = f.read(4)
    if magic != b' LBL':
        break

    num, namelen = struct.unpack('<II', f.read(8))
    name = f.read(namelen).decode('latin1')
    labels[name] = []

    for _ in range(num):
        magic = f.read(4)
        nchars = struct.unpack('<I', f.read(4))[0]
        s = bytes([(x ^ 0xff) for x in f.read(nchars * 2)]).decode('utf-16')
        
        if magic.lower() == b'wrts':
            nchars = struct.unpack('<I', f.read(4))[0]
            dialog = f.read(nchars).decode('latin1')
            s = {'text': s, 'dialog': dialog}

        labels[name].append(s)

print(yaml.dump({
    'language': lang,
    'translations': labels
}, allow_unicode=True))
