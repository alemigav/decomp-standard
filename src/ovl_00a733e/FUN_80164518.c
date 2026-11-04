/* FUN_80164518
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80164518  body 0x80164518..0x80164783  size 620 B
 * body sha256 36231c912616249a77eeb2954270ed5a0f6f3f4bc8708fbd62d88642e66971e3
 * provider record sha256 9230653b10bfe0f630a1da509eeb5a4c7d6be31fc785640852c953840866d6e6
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164518(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  ushort uVar4;
  
  bVar1 = *(byte *)((int)param_1 + 7);
  if (bVar1 == 1) {
LAB_80164608:
    FUN_80165e14(param_1,0x80);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    if ((*(uint *)param_1[0x85] & 0x10000) == 0) goto LAB_80164744;
    *(undefined1 *)((int)param_1 + 7) = 2;
    *(undefined1 *)((int)param_1 + 0x2bd) = 1;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    *param_1 = *param_1 | 8;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    func_0x80077d18(6,param_1);
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) goto LAB_80164744;
      *(undefined1 *)((int)param_1 + 7) = 1;
      param_1[0x7a] = 0xd000f00;
      iVar2 = func_0x80040bb4((5000 - param_1[10]) * (5000 - param_1[10]) +
                              (-0x40d8 - param_1[0xc]) * (-0x40d8 - param_1[0xc]));
      *(undefined2 *)((int)param_1 + 0x1e2) = 0xfab6;
      *(undefined2 *)(param_1 + 0x79) = 0;
      *(short *)(param_1 + 0x78) = (short)(iVar2 / 0x11);
      uVar3 = func_0x80032d14((int)*(short *)((int)param_1 + 0x2a),
                              (int)*(short *)((int)param_1 + 0x32),5000,0xffffbf28);
      *(undefined2 *)((int)param_1 + 0x2b6) = uVar3;
      *(undefined1 *)((int)param_1 + 0x2cd) = 0;
      *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 1;
      goto LAB_80164608;
    }
    if (bVar1 != 2) goto LAB_80164744;
    func_0x80032bd8(param_1,0,0);
    if ((*(char *)((int)param_1 + 0x207) == '\0') &&
       (iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100), iVar2 != 0)) {
      *(undefined1 *)((int)param_1 + 0x207) = 1;
      *param_1 = *param_1 | 0x400;
    }
    uVar4 = *(short *)((int)param_1 + 0x1e2) + 0x50;
    *(ushort *)((int)param_1 + 0x1e2) = uVar4;
    if (((int)((uint)uVar4 << 0x10) < 0) || ((int)param_1[0xb] < -6000)) goto LAB_80164744;
    *(undefined2 *)((int)param_1 + 6) = 0x100;
    param_1[10] = 5000;
    param_1[0xb] = 0xffffe890;
    param_1[0xc] = 0xffffbf28;
    func_0x80077d18(7,param_1);
    *(undefined1 *)((int)param_1 + 0x2cf) = 0x1c;
    *(undefined1 *)((int)param_1 + 0x2ce) = 7;
  }
  func_0x80052c6c(8,100,0);
LAB_80164744:
  *(char *)((int)param_1 + 0x1a2) = (char)((int)param_1[0xb] / 0x708);
  return;
}
