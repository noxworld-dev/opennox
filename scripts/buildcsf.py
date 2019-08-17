#!/usr/bin/env python3
import struct
import sys
import yaml

with open(sys.argv[1], 'r') as f:
    db = yaml.load(f.read())

num_strings = sum(map(len, db['translations'].values()))
with open('nox2.csf', 'wb') as f:
    f.write(struct.pack('<4sIIIII', b' FSC', 2, len(db['translations']), num_strings, 0, db['language']))

    for label, strings in db['translations'].items():
        label = label.encode('latin1')
        f.write(struct.pack('<4sII', b' LBL', len(strings), len(label)))
        f.write(label)

        for s in strings:
            if isinstance(s, str):
                f.write(struct.pack('<4sI', b' rtS', len(s)))
                f.write(bytes([(x ^ 0xff) for x in s.encode('utf-16-le')]))
            else:
                f.write(struct.pack('<4sI', b'WrtS', len(s['text'])))
                f.write(bytes([(x ^ 0xff) for x in s['text'].encode('utf-16-le')]))
                f.write(struct.pack('I', len(s['dialog'])))
                f.write(s['dialog'].encode('latin1'))
