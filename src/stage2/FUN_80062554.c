/* FUN_80062554
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062554  body 0x80062554..0x800625ab  size 88 B
 * body sha256 0819e85ec9b187cde2dff81f4db116fac45a20aec6ffb03316b8ab5af5430ea6
 * provider record sha256 1871a7c90dbec12dbc50ced2fe8de00375b2956d3f1ee8a6292b4785427e7f79
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80062554(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  char cVar4;
  int iVar2;
  undefined2 uVar3;
  
  switch(*(undefined1 *)(param_1 + 7)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0xa000700;
    *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) | 0x4000;
    (*(code *)(&PTR_LAB_8011102c)[(*(ushort *)(param_1 + 0x1aa) & 0xfff) - 1])(param_1);
    FUN_8005ab10(param_1,&UNK_80110378 + (*(ushort *)(param_1 + 0x1aa) & 0xfff) * 0x18);
    *(undefined1 *)(param_1 + 7) = 1;
    FUN_80077adc(0x10b0001,param_1 + 0x28);
    FUN_80052d10(0xf,0,(&DAT_80110f6e)[((*(ushort *)(param_1 + 0x1aa) & 0xfff) - 2) * 6],0);
  case 1:
    FUN_8005c308(param_1);
    iVar2 = FUN_80089d54(param_1,param_2,param_3,0x200);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0xb000700;
      *(undefined1 *)(param_1 + 7) = 2;
    }
    break;
  case 2:
    FUN_8005c308(param_1);
    DAT_800e112a = DAT_800e112a | 1;
    uVar1 = *(ushort *)(param_1 + 0x1aa) & 0xfff;
    FUN_8005ab48(param_1,(uVar1 - 1) * 0x10000 | 2,&UNK_80110378 + uVar1 * 0x18);
    FUN_80089d54(param_1,param_2,param_3,0x200);
    (*(code *)(&PTR_FUN_80111078)[(*(ushort *)(param_1 + 0x1aa) & 0xfff) - 1])(param_1);
    if ((param_4 & 0x100) == 0) {
      *(undefined2 *)(param_1 + 6) = 0x300;
      FUN_80077adc(0x10c0001,param_1 + 0x28);
      return;
    }
    if ((param_4 & 0x40) == 0) {
      *(undefined1 *)(param_1 + 7) = 3;
      return;
    }
    if (((*(short *)(param_1 + 0x1a8) != 0) &&
        (*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e))) &&
       ((*(byte *)(param_1 + 0x1e9) & 3) == 0)) {
      FUN_8005c3e8(param_1);
    }
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x1e8) = 0xd000700;
    *(undefined1 *)(param_1 + 7) = 4;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    FUN_80077adc(0x10c0001,param_1 + 0x28);
  case 4:
    cVar4 = FUN_80089d54(param_1,param_2,param_3,0x200);
    *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar4;
    if ((param_4 & 0x40) != 0) {
      iVar2 = FUN_8008cce4(*(ushort *)(param_1 + 0x1aa) & 0xfff);
      if (iVar2 != 0) {
        *(undefined2 *)(param_1 + 6) = 0x201;
        return;
      }
      if ((DAT_800df918 & 0x40) != 0) {
        cVar4 = FUN_8008d00c();
        uVar3 = 0x400;
        if (cVar4 == '\0') {
          FUN_80077adc(0x1010001,param_1 + 0x28);
        }
        else {
LAB_800628a0:
          *(undefined2 *)(param_1 + 6) = uVar3;
        }
      }
    }
    break;
  case 5:
    uVar3 = 0x100;
    goto LAB_800628a0;
  }
  cVar4 = DAT_800df8c0;
  if (((param_4 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -8;
  }
  if (((param_4 & 2) != 0) || ('\x19' < cVar4)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 8;
  }
  return;
}
