/* FUN_801708a4
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x801708a4  body 0x801708a4..0x80170fff  size 1884 B
 * body sha256 680ed5d55dfda5695fe0823d99c028508a45d27b1cbff7b64084ae115ce4c383
 * provider record sha256 43f281dbb2a0e414cd741af23c5343818ced226f1f49abb785b2e92bdaf870e5
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801708a4(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  undefined4 local_30;
  undefined1 local_2c;
  
  local_30 = 0xf100f10;
  local_2c = 0x11;
  DAT_800e10fa = 4;
  if ((_DAT_800e10ec & 8) == 0) {
    if ((_DAT_800e110c & 0x40000000) == 0) {
      DAT_800e10fa = 0;
      if ((int)_DAT_800e110c < 0) {
        DAT_800e10fa = 2;
      }
    }
    else {
      DAT_800e10fa = 1;
      if ((int)_DAT_800e110c < 0) {
        DAT_800e10fa = 3;
      }
    }
  }
  if ((DAT_800e9012 & 0xf0) != 0) {
    iVar1 = func_0x80007000();
    _DAT_800f9e30 = iVar1 * 0x41c64e6d + 0x3039;
    fVar3 = ((float)((_DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / 32767.0) * 14.0 + 1.0;
    fVar4 = fVar3;
    if (fVar3 < 0.0) {
      fVar4 = -fVar3;
    }
    fVar4 = fVar4 - (float)(int)fVar4;
    if (0.5 < fVar4) {
      if (0.0 < fVar3) {
        fVar3 = fVar3 + (1.0 - fVar4);
      }
      else {
        fVar3 = fVar3 - fVar4;
      }
    }
    else if (0.0 <= fVar3) {
      fVar3 = fVar3 - fVar4;
    }
    else {
      fVar3 = fVar3 - (1.0 - fVar4);
    }
    while ((uint)(DAT_800e9012 >> 4) == ((int)fVar3 & 0xffU)) {
      _DAT_800f9e30 = _DAT_800f9e30 * 0x41c64e6d + 0x3039;
      fVar3 = ((float)((_DAT_800f9e30 >> 0x10 & 0x7fffU) % 0x7fff) / 32767.0) * 14.0 + 1.0;
      fVar4 = fVar3;
      if (fVar3 < 0.0) {
        fVar4 = -fVar3;
      }
      fVar4 = fVar4 - (float)(int)fVar4;
      if (0.5 < fVar4) {
        if (0.0 < fVar3) {
          fVar3 = fVar3 + (1.0 - fVar4);
        }
        else {
          fVar3 = fVar3 - fVar4;
        }
      }
      else if (0.0 <= fVar3) {
        fVar3 = fVar3 - fVar4;
      }
      else {
        fVar3 = fVar3 - (1.0 - fVar4);
      }
    }
    DAT_800e9012 = DAT_800e9012 & 0xf | (byte)((int)fVar3 << 4);
  }
  FUN_80171000();
  if ((_DAT_800e10ec & 8) == 0) {
    if ((_DAT_800e110c & 0x40000000) == 0) {
      _DAT_800e8caa = 0;
      _DAT_800e1158 = 0x4972;
      _DAT_800e1160 = 0xfffff3a4;
      _DAT_800e1196 = 0x800;
    }
    else {
      _DAT_800e8caa = 4;
      _DAT_800e1158 = 0xffffba00;
      _DAT_800e1160 = 0xffffab26;
      _DAT_800e1196 = 400;
    }
    _DAT_800e8cac = 0;
    _DAT_800e8ca8 = 0;
    DAT_800e1138 = (int)_DAT_800e110c < 0;
    _DAT_800e9010 = 200;
    DAT_800e900f = 0;
    DAT_800e8b3a = DAT_800e1138;
  }
  else {
    _DAT_800e8ca8 = 2;
    _DAT_800e8caa = 4;
    _DAT_800e8cac = 3;
    _DAT_800e1158 = 0xffffe301;
    _DAT_800e1160 = 0xffffa054;
    _DAT_800e1196 = 0x800;
    if ((_DAT_800e10ec & 1) == 0) {
      DAT_800e1138 = 0xc;
      DAT_800e8b3a = 0xc;
      _DAT_800e9010 = 200;
    }
    else {
      DAT_800e1138 = 0xd;
      DAT_800e8b3a = 0xd;
      _DAT_800e9010 = 400;
    }
  }
  _DAT_800e115c = 0;
  DAT_80160c18 = 1;
  _DAT_800e1322 = _DAT_800e9010;
  _DAT_800e8b4a = _DAT_800e9010;
  _DAT_800e8cb4 = _DAT_800e9010;
  func_0x8008b2e4();
  func_0x8008b548();
  DAT_80160c18 = 0;
  _DAT_800e8b30 = 0;
  DAT_800e8b38 = 8;
  DAT_800e8b39 = DAT_800dfbe9;
  DAT_800e8b3b = *(undefined1 *)((int)&local_30 + (uint)DAT_800e10fa);
  DAT_800e8b3c = DAT_80119e73;
  DAT_800e8b3d = DAT_80119e74;
  DAT_800e8b3f = 0;
  DAT_800e8b3e = DAT_800e923e;
  DAT_800e13e6 = 0;
  _DAT_800e8b40 = 0;
  _DAT_800e13e4 = 0;
  _DAT_800e8b42 = DAT_80171ea0._0_2_;
  _DAT_800e110c = _DAT_800e110c & 0xc4000000;
  _DAT_800e8b44 = _DAT_800e110c;
  if ((_DAT_800e10ec & 8) != 0) {
    func_0x80083758(&DAT_800e110c,6);
    func_0x80083758(&DAT_800e8b44,6);
  }
  if ((_DAT_800e10ec & 1) != 0) {
    func_0x80083758(&DAT_800e110c,6);
    func_0x80083758(&DAT_800e8b44,6);
  }
  _DAT_800e8b4e = 0;
  _DAT_800e8b50 = 0xffff;
  if ((_DAT_800e10ec & 8) == 0) {
    _DAT_800e8b4c = DAT_80171e9c._0_2_;
    if ((_DAT_800e110c & 0x40000000) == 0) {
      _DAT_800e8b34 = 0;
      DAT_800e900e = 1;
      iVar1 = func_0x800837ac(&DAT_80172208,0x14);
      if (iVar1 != 0) {
        func_0x80083758(&DAT_800e8eb8,0x14);
      }
      iVar1 = func_0x800837ac(&DAT_80172208,0x13);
      if (iVar1 != 0) {
        func_0x80083758(&DAT_800e8eb8,0x13);
      }
    }
    else {
      _DAT_800e8b34 = 0;
      DAT_800e900e = 0;
      _DAT_800e8eb8 = 0;
      _DAT_800e8ebc = 0;
    }
    iVar1 = 2;
    _DAT_800e8b58 = DAT_80171ea8 & 1;
    if ((DAT_80171df4 & 0x10) != 0) {
      iVar1 = 3;
      DAT_800e8efc = 0xf;
      DAT_800e8efd = 0xff;
      DAT_800e8efe = 1;
    }
    iVar2 = iVar1 * 4;
    if ((DAT_80171df4 & 0x20) != 0) {
      iVar1 = iVar1 + 1;
      *(undefined1 *)(iVar2 + -0x7ff1710c) = 0x11;
      *(undefined1 *)(iVar2 + -0x7ff1710b) = 0xff;
      *(undefined1 *)(iVar2 + -0x7ff1710a) = 1;
    }
    if ((DAT_80171df4 & 0x40) != 0) {
      func_0x80083758(&DAT_800e8b58,0x12);
      iVar1 = iVar1 * 4;
      *(undefined1 *)(iVar1 + -0x7ff1710c) = 0x12;
      *(undefined1 *)(iVar1 + -0x7ff1710b) = 1;
      *(undefined1 *)(iVar1 + -0x7ff1710a) = 1;
    }
  }
  return;
}
