/* FUN_80062184
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062184  body 0x80062184..0x8006251f  size 924 B
 * body sha256 2348cef130822785f72188dec84a9e58f98366b51431e8dab4d2ccbf89c53c2e
 * provider record sha256 99293cb15878dbc91b6078dd9a5d13286a1d53d31b5dba6dcac4b47ddf39f5c8
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80062184(uint *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  short local_30 [8];
  
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
    param_1[0x78] = 0;
    *(undefined2 *)(param_1 + 0x79) = 0;
  }
  FUN_8005bdf4(param_1,*(undefined4 *)(param_1[0x8d] + 0x14e0),
               *(ushort *)((int)param_1 + 0x1aa) & 0xfff);
  uVar4 = *param_1 >> 0x1d;
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0x7e);
  if (iVar1 == 0) {
LAB_800622b4:
    cVar3 = *(char *)((int)param_1 + 0x1e9);
  }
  else {
    cVar3 = *(char *)((int)param_1 + 0x1e9);
    if (cVar3 == '\x03') {
      *(undefined1 *)((int)param_1 + 0x1e9) = 10;
      *(undefined1 *)((int)param_1 + 0x1ea) = 3;
      goto LAB_800622b4;
    }
  }
  if (cVar3 != '\0') {
    if ((cVar3 != '\x03') && (cVar3 != '\x06')) goto LAB_80062368;
    if (((param_4 & 0x40) == 0) ||
       (iVar1 = FUN_8008cce4(*(ushort *)((int)param_1 + 0x1aa) & 0xfff), iVar1 == 0)) {
      *(undefined1 *)((int)param_1 + 0x1e9) = 10;
      *(undefined1 *)((int)param_1 + 0x1ea) = 3;
      goto LAB_80062368;
    }
  }
  FUN_8005ab10(param_1,&UNK_80110370 +
                       (*(ushort *)((int)param_1 + 0x1aa) & 0xfff) * 0x18 +
                       (uint)(byte)(&DAT_80111024)[uVar4] * 8);
  FUN_8008cea0(*(ushort *)((int)param_1 + 0x1aa) & 0xfff,0);
  FUN_80059f1c(param_1,param_1[0x8d] + 0x1028);
  FUN_8005d700(param_1);
LAB_80062368:
  uVar2 = *(ushort *)((int)param_1 + 0x1aa) & 0xfff;
  FUN_8005ab48(param_1,(uVar2 - 1) * 0x10000 | uVar4,
               &UNK_80110370 + uVar2 * 0x18 + (uint)(byte)(&DAT_80111024)[uVar4] * 8);
  cVar3 = DAT_800df8c0;
  if (((param_4 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + -8;
  }
  if (((param_4 & 2) != 0) || ('\x19' < cVar3)) {
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
    iVar1 = FUN_80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      *(undefined2 *)((int)param_1 + 6) = 0x100;
      param_1[0x78] = 0;
      *(undefined2 *)(param_1 + 0x79) = 0;
    }
    if ((((*(short *)(param_1 + 0x6a) != 0) &&
         (*(short *)(param_1 + 0x6a) < *(short *)((int)param_1 + 0x25e))) &&
        (*(byte *)((int)param_1 + 0x1e9) < 6)) && ((*(byte *)((int)param_1 + 0x1e9) & 1) != 0)) {
      FUN_8005c3e8(param_1);
    }
    (*(code *)(&PTR_FUN_80111078)[(*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 1])(param_1);
  }
  return;
}
