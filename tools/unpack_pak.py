#!/usr/bin/env python3
"""Unpack a web/sprites-<region>.pak into plain files for the microSD.

The .pak is only a container for the web installer (see pack_bundle.py). When
the USB route fails or the card is simply easier to fill from a PC, this writes
the same files the installer would have sent: mons/pNNN.bin, mons/psNNN.bin and
mons/thumbs.bin. Copy the resulting `mons` folder to the ROOT of the card.

  python3 tools/unpack_pak.py web/sprites-kanto.pak out/
"""
import os
import struct
import sys

def unpack(pak, dest):
    with open(pak, 'rb') as f:
        if f.read(4) != b'TPAK':
            raise SystemExit(f'{pak}: not a TPAK file')
        (count,) = struct.unpack('<H', f.read(2))
        index = []
        for _ in range(count):
            (n,) = struct.unpack('<B', f.read(1))
            name = f.read(n).decode()
            (size,) = struct.unpack('<I', f.read(4))
            index.append((name, size))
        for name, size in index:
            out = os.path.join(dest, name)
            os.makedirs(os.path.dirname(out), exist_ok=True)
            with open(out, 'wb') as o:
                o.write(f.read(size))
    print(f'{pak}: {count} files -> {dest}')

if __name__ == '__main__':
    if len(sys.argv) < 3:
        raise SystemExit(__doc__)
    for p in sys.argv[1:-1]:
        unpack(p, sys.argv[-1])
