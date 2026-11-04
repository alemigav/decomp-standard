/* FUN_801621a0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801621a0  body 0x801621a0..0x801623cb  size 556 B
 * body sha256 79ca0793caab1db0591aa214666dce5d0742c2935e5aa8cef8c6c1644fa48c1e
 * provider record sha256 89e8378ab870e789112d915d062d81595312c259e4487654692002417b58a2cb
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_801621a0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  undefined1 uVar4;
  undefined1 uVar5;
  uint uVar3;
  
  uVar5 = 0;
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 == 1) {
    func_0x80032b5c(param_1,0);
    if ((param_1[0x6b] & 1) != 0) {
      uVar3 = func_0x80033604(param_1);
      uVar4 = 3;
      if ((uVar3 & 0x1f) == 0) {
        uVar4 = 2;
      }
      *(undefined1 *)((int)param_1 + 6) = uVar4;
      uVar4 = func_0x80065628();
      *(undefined1 *)(param_1 + 0xad) = uVar4;
      if (*(char *)((int)param_1 + 6) == '\x02') {
        *(undefined2 *)((int)param_1 + 0x1f6) = 0x5a;
        param_1[0x7a] = 0xf00;
      }
    }
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      *(undefined2 *)(param_1 + 0x78) = 0x1e;
      *(undefined1 *)((int)param_1 + 6) = 1;
      *(undefined2 *)(param_1 + 0x79) = 0;
      *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
      *param_1 = *param_1 & 0xefffffff | 0x4000000;
      *(undefined1 *)((int)param_1 + 0x2b5) = 0;
      *(undefined1 *)((int)param_1 + 0x2c9) = 0;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    }
  }
  else if (bVar1 == 2) {
    sVar2 = *(short *)((int)param_1 + 0x1f6);
    *(short *)((int)param_1 + 0x1f6) = sVar2 + -1;
    if (sVar2 == 1) {
      *(undefined1 *)((int)param_1 + 6) = 3;
      param_1[0x7a] = 0x1000f00;
    }
  }
  else if (bVar1 == 3) {
    uVar5 = func_0x800653d0(param_1,0,*(undefined1 *)(param_1 + 0xad),1);
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x98),(int)*(short *)((int)param_1 + 0x262),
                    0x10);
    func_0x80032b5c(param_1,0);
    if ((param_1[0x6b] & 1) == 0) {
      *(undefined1 *)((int)param_1 + 6) = 1;
    }
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  FUN_801664d8(param_1);
  if ((*(char *)((int)param_1 + 699) == '\0') &&
     (uVar3 = func_0x80033604(param_1), (uVar3 & 0x3f) == 0)) {
    uVar3 = func_0x80033604(param_1);
    *(undefined *)((int)param_1 + 699) = (&DAT_80166c80)[uVar3 & 7];
  }
  FUN_80166980(param_1,4,6);
  return uVar5;
}
