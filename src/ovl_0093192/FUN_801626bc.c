/* FUN_801626bc
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x801626bc  body 0x801626bc..0x8016287b  size 448 B
 * body sha256 6944b5a3306a23fddcbb64067f1939314d9de24e5f85e979c8d6edba14436839
 * provider record sha256 ab7d506484e6850423ca3efb2e6a3dd2c85ce78f1b75e94735742543e8d145f8
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801626bc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  byte bVar5;
  int iVar4;
  undefined2 uVar6;
  uint uVar7;
  
  uVar7 = param_1[0xad];
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 0x1c2;
    uVar3 = func_0x80033604();
    uVar6 = 0xffe0;
    if ((uVar3 & 1) != 0) {
      uVar6 = 0x20;
    }
    *(undefined2 *)((int)param_1 + 0x1f6) = uVar6;
    bVar5 = func_0x80033604();
    *(byte *)((int)param_1 + 0x206) = bVar5 & 0x1f;
    *param_1 = *param_1 | 0xc000000;
  }
  iVar4 = func_0x80032e74(param_1,*(undefined4 *)(uVar7 + 0x28),*(undefined4 *)(uVar7 + 0x30),0x100)
  ;
  cVar1 = *(char *)((int)param_1 + 0x2ba);
  *(char *)((int)param_1 + 0x2ba) = -*(char *)((int)param_1 + 0x2ba);
  *(short *)((int)param_1 + 0x66) =
       *(short *)((int)param_1 + 0x66) + (short)cVar1 + *(short *)((int)param_1 + 0x1f6);
  func_0x80089d54(param_1,param_2,param_3,0x400);
  bVar5 = *(char *)((int)param_1 + 0x206) + 1;
  *(byte *)((int)param_1 + 0x206) = bVar5;
  if ((bVar5 & 0xf) == 0) {
    FUN_80162b9c(param_1,0,0x82);
    bVar5 = func_0x80033604();
    *(byte *)((int)param_1 + 0x206) = *(char *)((int)param_1 + 0x206) + (bVar5 & 7);
  }
  if (param_1[0xad] == 0x800e1130) {
    uVar3 = param_1[0xa3];
  }
  else {
    uVar3 = param_1[0xa4];
  }
  if ((((int)uVar3 < 2000) && (iVar4 == 0)) && ((*(byte *)(uVar7 + 0x26f) & 0x80) == 0)) {
    *(undefined1 *)((int)param_1 + 5) = 3;
    *(undefined2 *)((int)param_1 + 6) = 0;
  }
  param_1[0xb] = (int)*(short *)(param_1 + 0x6a) + 10;
  iVar4 = FUN_80162c90(param_1);
  if (iVar4 < 0) {
    sVar2 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar2 + -1;
    if (sVar2 == 1) {
      *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
      param_1[1] = 0x3000000;
    }
  }
  else {
    *(undefined1 *)((int)param_1 + 5) = 1;
    *(undefined2 *)((int)param_1 + 6) = 0;
  }
  return;
}
