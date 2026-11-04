/* FUN_80061ccc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80061ccc  body 0x80061ccc..0x8006214f  size 1156 B
 * body sha256 5e1f6dfcb9843f94d57ee286a3302e15040f7ae7866314fac1aad9fb560bf6ec
 * provider record sha256 08834ceece070b12691add41b0dd720a55669ab95fd9a6a1fe5866a646a4b3e8
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80061ccc(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  int iVar5;
  byte bVar6;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  byte local_30 [8];
  
  local_30[0] = 4;
  local_30[1] = 1;
  local_30[2] = 2;
  bVar6 = *(byte *)(param_1 + 7);
  if (bVar6 != 1) {
    if (1 < bVar6) {
      if (bVar6 == 2) {
        FUN_800334c8(param_1,param_2,param_3,0);
        iVar5 = FUN_80089d54(param_1,param_2,param_3,0x200);
        if (iVar5 != 0) {
          *(undefined2 *)(param_1 + 6) = 0x100;
          *(undefined4 *)(param_1 + 0x1e0) = 0;
          *(undefined2 *)(param_1 + 0x1e4) = 0;
        }
        FUN_80032b5c(param_1,0);
        if (((*(short *)(param_1 + 0x1a8) != 0) &&
            (*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e))) &&
           ((*(byte *)(param_1 + 0x1e9) < 6 && ((*(byte *)(param_1 + 0x1e9) & 1) != 0)))) {
          FUN_8005c3e8(param_1);
        }
        if (*(char *)(param_1 + 0x1e9) == '\x01') {
          local_38 = 0x82;
          local_36 = 0x6b8;
          local_34 = 0;
          FUN_80037780(0x6021000,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x1060,
                       &local_38);
        }
        DAT_800e110c = DAT_800e110c & 0xffffff7f;
      }
      goto LAB_80062070;
    }
    if (bVar6 != 0) goto LAB_80062070;
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0xa000700;
    bVar6 = 2;
    DAT_800e112a = DAT_800e112a | 1;
    (*(code *)(&PTR_LAB_8011102c)[(*(ushort *)(param_1 + 0x1aa) & 0xfff) - 1])(param_1);
    do {
      uVar3 = *(ushort *)(param_1 + 0x1aa);
      bVar1 = local_30[bVar6];
      bVar2 = (&DAT_80111024)[bVar1];
      FUN_8005ab10(param_1,&UNK_80110370 + (uVar3 & 0xfff) * 0x18 + (uint)bVar2 * 8);
      iVar5 = FUN_8005ab48(param_1,((*(ushort *)(param_1 + 0x1aa) & 0xfff) - 1) * 0x10000 |
                                   (uint)bVar1 | 0x8000,
                           &UNK_80110370 + (uVar3 & 0xfff) * 0x18 + (uint)bVar2 * 8);
      *(int *)(param_1 + 0x274) = iVar5;
      if (iVar5 != 0) break;
      bVar6 = bVar6 - 1;
    } while (bVar6 != 0);
    FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,0);
  }
  iVar5 = FUN_80089d54(param_1,param_2,param_3,0x200);
  if (iVar5 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  if ((*(char *)(param_1 + 0x1e9) == '\x04') && (*(int *)(param_1 + 0x274) != 0)) {
    *(undefined1 *)(param_1 + 7) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0xb000000;
    FUN_8008cea0(*(ushort *)(param_1 + 0x1aa) & 0xfff,1);
    FUN_8005d700(param_1);
  }
  if (*(char *)(param_1 + 0x1e9) == '\x01') {
    local_38 = 0x82;
    local_36 = 0x514;
    local_34 = 0;
    FUN_80037780(0x1281800,0,*(int *)(param_1 + 0x234) + 0x1060,&local_38);
    if ((*(char *)(param_1 + 0x1e9) == '\x01') && (*(int *)(param_1 + 0x274) == 0)) {
      local_38 = 0x82;
      local_36 = 0x6b8;
      local_34 = 0;
      FUN_80037780(0x6031000,(int)*(short *)(param_1 + 0x66),*(int *)(param_1 + 0x234) + 0x1060,
                   &local_38);
    }
  }
  if ((((*(short *)(param_1 + 0x1a8) != 0) &&
       (*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e))) &&
      (*(byte *)(param_1 + 0x1e9) < 6)) && ((*(byte *)(param_1 + 0x1e9) & 1) != 0)) {
    FUN_8005c3e8(param_1);
  }
LAB_80062070:
  cVar4 = DAT_800df8c0;
  if (((param_4 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -8;
  }
  if (((param_4 & 2) != 0) || ('\x19' < cVar4)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 8;
  }
  if (((param_4 & 0x100) == 0) &&
     (((&DAT_80110e26)[((*(ushort *)(param_1 + 0x1aa) & 0xfff) - 1) * 3] & 0x7f) <
      *(byte *)(param_1 + 0x1e9))) {
    *(undefined2 *)(param_1 + 6) = 0x100;
  }
  return;
}
