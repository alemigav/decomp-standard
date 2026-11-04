/* FUN_8017c480
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017c480  body 0x8017c480..0x8017cfe3  size 2916 B
 * body sha256 2146b7aa76a10544f0316fb5172f570cd57f842070b31c12c53dc5c88c096012
 * provider record sha256 b3260b67d655005cd05acc5661dd8368c4e4bd1c95f0e1549b2925453658657e
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017c480(void)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  
  FUN_8017dc48(0,DAT_80119e74,DAT_8017e5cc);
  FUN_8017dc48(3,DAT_80119e73,DAT_8017e5cc);
  if ((_DAT_800df918 & 0x2000) != 0) {
LAB_8017c504:
    DAT_8017e5c9 = 2;
    DAT_8017e5ca = 0;
    DAT_8017e5d0 = 0x2c808080;
    DAT_8017e5cd = 0;
    DAT_8017e5bf = DAT_8017e5bf | 8;
    func_0x80077adc(0x4050000,0);
    return;
  }
  if ((_DAT_800df918 & 0x1000) != 0) {
    if ((&DAT_8017e5c4)[DAT_8017e5cc] != '\x03') {
      return;
    }
    goto LAB_8017c504;
  }
  if ((_DAT_800df90c & 0xa000) == 0) {
    DAT_8017e5c1 = '\x01';
    DAT_8017e5c3 = 0;
  }
  else if (9 < DAT_8017e5c3) {
    DAT_8017e5c3 = DAT_8017e5c3 - 1;
    DAT_8017e5c1 = '\n';
  }
  if (-1 < _DAT_800e10ec) goto LAB_8017cd08;
  if ((_DAT_800df90c & 0x1000) != 0) {
    DAT_8017e5ca = 0;
    DAT_8017e5d0 = 0x2c808080;
    (&DAT_8017df58)
    [((uint)(byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] +
     (uint)(byte)(&DAT_8017e5c4)[DAT_8017e5cc]) * 8] = 5;
    bVar1 = (&DAT_8017e5c4)[DAT_8017e5cc];
    if (bVar1 < 4) {
      (&DAT_8017e5c4)[DAT_8017e5cc] = bVar1 - 1;
      if ((&DAT_8017e5c4)[DAT_8017e5cc] == -1) {
        (&DAT_8017e5c4)[DAT_8017e5cc] = '\0';
      }
      else {
        func_0x80077adc(0x4040000,0);
      }
    }
  }
  if ((_DAT_800df90c & 0x4000) != 0) {
    DAT_8017e5ca = 0;
    DAT_8017e5d0 = 0x2c808080;
    uVar5 = (uint)DAT_8017e5cc;
    pbVar6 = &DAT_8017e5c4 + uVar5;
    if ((*pbVar6 == 0) || (*pbVar6 == 4)) {
      iVar2 = (uint)(byte)(&DAT_8017de20)[uVar5 * 2] + (uint)*pbVar6;
      uVar3 = 1;
    }
    else {
      iVar2 = (uint)(byte)(&DAT_8017de20)[uVar5 * 2] + (uint)*pbVar6;
      uVar3 = 5;
    }
    (&DAT_8017df58)[iVar2 * 8] = uVar3;
    pbVar6 = &DAT_8017e5c4 + DAT_8017e5cc;
    if (*pbVar6 < 4) {
      *pbVar6 = *pbVar6 + 1;
      if ((&DAT_8017e5c4)[DAT_8017e5cc] == '\x04') {
        (&DAT_8017e5c4)[DAT_8017e5cc] = '\x03';
        goto LAB_8017c790;
      }
    }
    else {
      *pbVar6 = 1;
    }
    func_0x80077adc(0x4040000,0);
  }
LAB_8017c790:
  if ((_DAT_800df90c & 0x8000) != 0) {
    DAT_8017e5ca = 0;
    DAT_8017e5d0 = 0x2c808080;
    uVar5 = (uint)DAT_8017e5cc;
    bVar1 = (&DAT_8017e5c4)[uVar5];
    if (bVar1 == 1) {
      DAT_8017e5c3 = DAT_8017e5c3 + 1;
      DAT_80119e74 = DAT_80119e74 - DAT_8017e5c1;
      if (DAT_80119e74 < 0x65) {
        func_0x80077adc(0x4040000,0);
      }
      else {
        DAT_80119e74 = 0;
      }
      FUN_8017dc48(0,DAT_80119e74,DAT_8017e5cc);
      (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 7) * 8] = 1;
      func_0x80079344((int)DAT_80119ee6,(int)_DAT_80119ee8,(int)_DAT_80119eea);
      func_0x80079344((int)DAT_80119eee,(int)_DAT_80119ef0,(int)_DAT_80119ef2);
      func_0x80079344((int)DAT_80119ef6,(int)_DAT_80119ef8,(int)_DAT_80119efa);
      func_0x800750b0(1);
    }
    else if (bVar1 < 2) {
      if (bVar1 == 0) {
        uVar4 = 1;
        (&DAT_8017df58)[(uint)(byte)(&DAT_8017de20)[uVar5 * 2] * 8] = 5;
        (&DAT_8017e5c4)[DAT_8017e5cc] = 4;
        DAT_800dfbe9 = 1;
LAB_8017ca34:
        func_0x8007604c(uVar4);
        func_0x80077adc(0x4040000,0);
      }
    }
    else if (bVar1 == 2) {
      DAT_8017e5c3 = DAT_8017e5c3 + 1;
      DAT_80119e73 = DAT_80119e73 - DAT_8017e5c1;
      if (DAT_80119e73 < 0x65) {
        func_0x80077adc(0x4040000,0);
      }
      else {
        DAT_80119e73 = 0;
      }
      FUN_8017dc48(3,DAT_80119e73,DAT_8017e5cc);
      (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 0xb) * 8] = 1;
      func_0x800750b0();
    }
    else if (bVar1 == 4) {
      (&DAT_8017df58)[((byte)(&DAT_8017de20)[uVar5 * 2] + 4) * 8] = 5;
      uVar4 = 0;
      (&DAT_8017e5c4)[DAT_8017e5cc] = 0;
      DAT_800dfbe9 = 0;
      goto LAB_8017ca34;
    }
  }
  if ((_DAT_800df90c & 0x2000) != 0) {
    DAT_8017e5ca = 0;
    DAT_8017e5d0 = 0x2c808080;
    uVar5 = (uint)DAT_8017e5cc;
    bVar1 = (&DAT_8017e5c4)[uVar5];
    if (bVar1 == 1) {
      DAT_8017e5c3 = DAT_8017e5c3 + 1;
      DAT_80119e74 = DAT_80119e74 + DAT_8017e5c1;
      if (DAT_80119e74 < 0x65) {
        func_0x80077adc(0x4040000,0);
      }
      else {
        DAT_80119e74 = 100;
      }
      FUN_8017dc48(0,DAT_80119e74,DAT_8017e5cc);
      (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 9) * 8] = 1;
      func_0x80079344((int)DAT_80119ee6,(int)_DAT_80119ee8,(int)_DAT_80119eea);
      func_0x80079344((int)DAT_80119eee,(int)_DAT_80119ef0,(int)_DAT_80119ef2);
      func_0x80079344((int)DAT_80119ef6,(int)_DAT_80119ef8,(int)_DAT_80119efa);
      func_0x800750b0(1);
    }
    else {
      if (bVar1 < 2) {
        if (bVar1 != 0) goto LAB_8017cd08;
        uVar4 = 1;
        (&DAT_8017df58)[(uint)(byte)(&DAT_8017de20)[uVar5 * 2] * 8] = 5;
        (&DAT_8017e5c4)[DAT_8017e5cc] = 4;
        DAT_800dfbe9 = 1;
      }
      else {
        if (bVar1 == 2) {
          DAT_8017e5c3 = DAT_8017e5c3 + 1;
          DAT_80119e73 = DAT_80119e73 + DAT_8017e5c1;
          if (DAT_80119e73 < 0x65) {
            func_0x80077adc(0x4040000,0);
          }
          else {
            DAT_80119e73 = 100;
          }
          FUN_8017dc48(3,DAT_80119e73,DAT_8017e5cc);
          (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 0xd) * 8] = 1;
          func_0x800750b0();
          goto LAB_8017cd08;
        }
        if (bVar1 != 4) goto LAB_8017cd08;
        (&DAT_8017df58)[((byte)(&DAT_8017de20)[uVar5 * 2] + 4) * 8] = 5;
        uVar4 = 0;
        (&DAT_8017e5c4)[DAT_8017e5cc] = 0;
        DAT_800dfbe9 = 0;
      }
      func_0x8007604c(uVar4);
      func_0x80077adc(0x4040000,0);
    }
  }
LAB_8017cd08:
  (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 7) * 8] = 0;
  (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 8) * 8] = 1;
  (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 9) * 8] = 0;
  (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 10) * 8] = 1;
  (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 0xb) * 8] = 0;
  (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 0xc) * 8] = 1;
  (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 0xd) * 8] = 0;
  (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 0xe) * 8] = 1;
  if ((_DAT_800df90c & 0x8000) != 0) {
    if ((&DAT_8017e5c4)[DAT_8017e5cc] == '\x01') {
      (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 7) * 8] = 1;
      (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 8) * 8] = 0;
    }
    if ((&DAT_8017e5c4)[DAT_8017e5cc] == '\x02') {
      (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 0xb) * 8] = 1;
      (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 0xc) * 8] = 0;
    }
  }
  if ((_DAT_800df90c & 0x2000) == 0) {
    return;
  }
  uVar5 = (uint)DAT_8017e5cc;
  if ((&DAT_8017e5c4)[uVar5] == '\x01') {
    (&DAT_8017df58)[((byte)(&DAT_8017de20)[uVar5 * 2] + 9) * 8] = 1;
    (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 10) * 8] = 0;
    uVar5 = (uint)DAT_8017e5cc;
  }
  if ((&DAT_8017e5c4)[uVar5] == '\x02') {
    (&DAT_8017df58)[((byte)(&DAT_8017de20)[uVar5 * 2] + 0xd) * 8] = 1;
    (&DAT_8017df58)[((byte)(&DAT_8017de20)[(uint)DAT_8017e5cc * 2] + 0xe) * 8] = 0;
    return;
  }
  return;
}
