/* FUN_800585f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800585f4  body 0x800585f4..0x80058607  size 20 B
 * body sha256 021ab4bbca45fac1938644dba488170129a492757c6d3d269709d7901d27b1d0
 * provider record sha256 caf680729d8d7daebaf3877ff3fd6eb0c591516f250d3be4dfe04f50fbf7a8d9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8005850c::caseD_2(void)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  uint *unaff_s0;
  
  *(undefined1 *)((int)unaff_s0 + 7) = 3;
  *(undefined1 *)(unaff_s0 + 0x7a) = 6;
  *(undefined1 *)((int)unaff_s0 + 0x1ea) = 3;
  if (unaff_s0[0xa0] != 0) {
    FUN_8004f634(&DAT_800e1130,unaff_s0[0xa0],(uint)*(byte *)((int)unaff_s0 + 9) << 8,4);
  }
  if (*(char *)((int)unaff_s0 + 0x1e9) == '\x11') {
    *(byte *)((int)unaff_s0 + 0x26f) = *(byte *)((int)unaff_s0 + 0x26f) | 0x80;
    *unaff_s0 = *unaff_s0 | 8;
    *(char *)((int)unaff_s0 + 0x1a2) = *(char *)((int)unaff_s0 + 0x1a2) + '\x01';
  }
  if (*(char *)(unaff_s0 + 2) == '\x0f') {
    cVar3 = *(char *)((int)unaff_s0 + 0x1e9);
    if (cVar3 == '9') {
      uVar1 = FUN_80033604();
      if ((uVar1 & 3) != 0) {
        unaff_s0[0x7a] = 0x6560500;
      }
      cVar3 = *(char *)((int)unaff_s0 + 0x1e9);
    }
    if (cVar3 == 'c') {
      *(undefined2 *)(unaff_s0 + 0x78) = 0x224;
      FUN_80032b5c();
      unaff_s0[0xb] = unaff_s0[0xb] - 0x708;
      *(short *)((int)unaff_s0 + 0x25e) = *(short *)((int)unaff_s0 + 0x25e) + -0x708;
    }
    cVar3 = *(char *)((int)unaff_s0 + 0x1e9);
    cVar2 = 'w';
  }
  else {
    cVar3 = *(char *)((int)unaff_s0 + 0x1e9);
    if (cVar3 == '\x1d') {
      *(undefined2 *)(unaff_s0 + 0x78) = 1000;
      FUN_80032b5c();
      unaff_s0[0xb] = unaff_s0[0xb] - 0x708;
      *(short *)((int)unaff_s0 + 0x25e) = *(short *)((int)unaff_s0 + 0x25e) + -0x708;
      cVar3 = *(char *)((int)unaff_s0 + 0x1e9);
      cVar2 = '1';
    }
    else {
      cVar2 = '1';
    }
  }
  if (cVar3 == cVar2) {
    *(byte *)((int)unaff_s0 + 0x26f) = *(byte *)((int)unaff_s0 + 0x26f) & 0x7f;
    *unaff_s0 = *unaff_s0 & 0xfffffff3;
  }
  cVar3 = FUN_80089d54();
  *(char *)((int)unaff_s0 + 7) = *(char *)((int)unaff_s0 + 7) + cVar3;
  if (((*(short *)(unaff_s0 + 0x6a) < *(short *)((int)unaff_s0 + 0x25e)) &&
      (*(byte *)((int)unaff_s0 + 0x1e9) < 0xf)) && ((*(byte *)((int)unaff_s0 + 0x1e9) & 1) != 0)) {
    FUN_8005c3e8();
  }
  if ((*(uint *)unaff_s0[0x85] & 0x4000) != 0) {
    FUN_80077f30(1,((*(uint *)unaff_s0[0x85] & 0x2000) >> 0xd) * 3 + 4);
    DAT_800e112a = DAT_800e112a | 4;
  }
  return;
}
