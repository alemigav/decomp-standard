/* FUN_8005d2cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005d2cc  body 0x8005d2cc..0x8005d6ff  size 1076 B
 * body sha256 f7123f55aba485149d1012c42c3f6fc9ce918772268e6b83a65e6c3940e7500f
 * provider record sha256 32f67ca340db5133d3365e7c9610fba43076b178b03c6d7fd9a28afb00a7bef5
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005d2cc(uint *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort uVar6;
  short local_30 [8];
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  local_30[0] = 0;
  local_30[1] = 0xe;
  local_30[2] = 10;
  local_30[3] = 0;
  local_30[4] = 0xc;
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
    param_1[0x7a] = local_30[*(ushort *)(param_1 + 0x7c) >> 0xd] * 0x1000000 + 0x700;
    DAT_800e112a = DAT_800e112a | 1;
    (*(code *)(&PTR_LAB_8011102c)[(*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 1])(param_1);
    if (((*(char *)(param_1 + 2) == '\b') || (*(char *)(param_1 + 2) == '\n')) &&
       ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 2)) {
      uVar5 = *(undefined4 *)(param_1[0x8d] + 0x1078);
      uVar6 = 2;
    }
    else {
      uVar5 = *(undefined4 *)(param_1[0x8d] + 0x14e0);
      uVar6 = *(ushort *)((int)param_1 + 0x1aa) & 0xfff;
    }
    FUN_8005bdf4(param_1,uVar5,uVar6);
    FUN_8005ab10(param_1,&UNK_80110370 +
                         (*(ushort *)((int)param_1 + 0x1aa) & 0xfff) * 0x18 +
                         (uint)(byte)(&DAT_80111024)[*param_1 >> 0x1d] * 8);
    param_1[0x78] = 0;
    *(undefined2 *)(param_1 + 0x79) = 0;
    FUN_80059f1c(param_1,param_1[0x8d] + 0x1028);
    FUN_8005d700(param_1);
  }
  uVar4 = *(ushort *)((int)param_1 + 0x1aa) & 0xfff;
  if (3 < uVar4 - 9) {
    FUN_8005ab48(param_1,(uVar4 - 1) * 0x10000 | *param_1 >> 0x1d,
                 &UNK_80110370 + uVar4 * 0x18 + (uint)(byte)(&DAT_80111024)[*param_1 >> 0x1d] * 8);
  }
  cVar1 = DAT_800df8c0;
  if (((param_4 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + -8;
  }
  if (((param_4 & 2) != 0) || ('\x19' < cVar1)) {
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 8;
  }
  if (((param_4 & 0x100) == 0) &&
     (((&DAT_80110e26)[((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 1) * 3] & 0x7f) <
      *(byte *)((int)param_1 + 0x1e9))) {
    *(undefined2 *)((int)param_1 + 6) = 0x100;
    param_1[0x78] = 0;
    *(undefined2 *)(param_1 + 0x79) = 0;
  }
  else {
    uVar6 = *(ushort *)((int)param_1 + 0x1aa) & 0xfff;
    if ((uVar6 == 8) || (uVar6 == 6)) {
      FUN_800334c8(param_1,param_2,param_3,0);
    }
    iVar2 = FUN_80089d54(param_1,param_2,param_3,0x200);
    if (iVar2 != 0) {
      *(undefined2 *)((int)param_1 + 6) = 0x100;
      param_1[0x78] = 0;
      *(undefined2 *)(param_1 + 0x79) = 0;
    }
    if (*(short *)(param_1 + 0x6a) != 0) {
      if (((*(short *)(param_1 + 0x6a) < *(short *)((int)param_1 + 0x25e)) &&
          (*(byte *)((int)param_1 + 0x1e9) < 6)) && ((*(byte *)((int)param_1 + 0x1e9) & 1) != 0)) {
        FUN_8005c3e8(param_1);
      }
      uVar4 = param_1[0x8d];
      local_20 = 0;
      local_1e = 300;
      local_1c = 0;
      if ((int)*(short *)(param_1 + 0x6a) < *(int *)(uVar4 + 0x1078) + 300) {
        uVar3 = FUN_80033604();
        FUN_80037780((uVar3 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)((int)param_1 + 0x66),
                     uVar4 + 0x1060,&local_20);
      }
      uVar4 = param_1[0x8d];
      if ((int)*(short *)(param_1 + 0x6a) < *(int *)(uVar4 + 0x14e0) + 200) {
        uVar3 = FUN_80033604();
        FUN_80037780((uVar3 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)((int)param_1 + 0x66),
                     uVar4 + 0x14c8,&local_20);
      }
    }
    FUN_80032b5c(param_1,0);
    (*(code *)(&PTR_FUN_80111078)[(*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 1])(param_1);
  }
  return;
}
