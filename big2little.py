"Convert binfiles from big endian to little endian"
from pathlib import Path
import numpy as np

def big2little(fpath: Path):
    name = fpath.name.replace(".", "l.")
    outpath = fpath.with_name(name)
    print(outpath)
    arr = np.fromfile(fpath, np.dtype(">d"), sep="").astype(np.double)
    with outpath.open("wb") as fp:
        bts = arr.tobytes()
        fp.write(bts)

def read_l():
    fpath = (Path.home() / "Downloads/125321/NormalUS1.bin").absolute()
    outpath = fpath.with_name("NormalUS1l.bin")
    arr = np.fromfile(outpath, np.dtype("d"), sep="")
    arr = arr.reshape((1000, 6400)).T

    import matplotlib.pyplot as plt
    breakpoint()


def main():
    fpath = (Path.home() / "Downloads/125321").absolute()

    for f in fpath.glob("*.bin"):
        if f.name.endswith("l.bin"):
            continue
        
        print(f)
        big2little(f)

if __name__ == "__main__":
    # main()
    read_l()
