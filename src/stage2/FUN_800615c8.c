/* FUN_800615c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800615c8  body 0x800615c8..0x8006169b  size 212 B
 * body sha256 d4824b9b2c2d408e6f4545acdef993ab06dbaed14e96cfc05bc1a8291bf55b8f
 * provider record sha256 a7956ad6b6359a68b1710560abb560bed9532d2f82aa8db10349d620966e5590
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800615c8(uint *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined1 uVar1;
  short sVar2;
  uint uVar3;
  ushort uVar5;
  char cVar7;
  int iVar4;
  undefined2 uVar6;
  ushort uVar8;
  uint uVar9;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  
  local_40 = 0x10;
  local_3c = 0xa0000;
  local_38 = 0xd;
  local_30 = 0x11;
  local_2c = 0xb0000;
  local_28 = 0xe;
  FUN_8005bdf4(param_1,*(undefined4 *)(param_1[0x8d] + 0x14e0),
               *(ushort *)((int)param_1 + 0x1aa) & 0xfff);
  uVar9 = *param_1 >> 0x1d;
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    param_1[0x7a] =
         *(short *)((int)&local_40 + (uint)(*(ushort *)(param_1 + 0x7c) >> 0xd) * 2) * 0x1000000 +
         0x700;
    (*(code *)(&PTR_LAB_8011102c)[(*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 1])(param_1);
    FUN_80052d10(10,0,(&DAT_80110f6e)[((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 2) * 6],0);
  case 1:
    break;
  case 2:
    goto switchD_80061694_caseD_2;
  case 3:
    sVar2 = *(short *)((int)&local_30 + (uint)(*(ushort *)(param_1 + 0x7c) >> 0xd) * 2);
    *(undefined1 *)((int)param_1 + 7) = 4;
    param_1[0x7a] = sVar2 * 0x1000000 + 0x700;
  case 4:
    cVar7 = FUN_80089d54(param_1,param_2,param_3,0x200);
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar7;
    if ((param_4 & 0x40) != 0) {
      iVar4 = FUN_8008cce4(*(ushort *)((int)param_1 + 0x1aa) & 0xfff);
      if (iVar4 != 0) {
        *(undefined2 *)((int)param_1 + 6) = 0x201;
        return;
      }
      if ((DAT_800df918 & 0x40) != 0) {
        cVar7 = FUN_8008d00c();
        uVar6 = 0x400;
        if (cVar7 == '\0') {
          FUN_80077adc(0x1010001,param_1 + 10);
        }
        else {
LAB_80061b1c:
          *(undefined2 *)((int)param_1 + 6) = uVar6;
        }
      }
    }
    goto switchD_80061694_default;
  case 5:
    uVar6 = 0x100;
    goto LAB_80061b1c;
  default:
    goto switchD_80061694_default;
  }
  uVar1 = *(undefined1 *)((int)&local_40 + (uint)(*(ushort *)(param_1 + 0x7c) >> 0xd) * 2 + 1);
  *(undefined1 *)((int)param_1 + 0x1ea) = 7;
  *(undefined1 *)(param_1 + 0x7a) = uVar1;
  FUN_8005ab10(param_1,&UNK_80110370 +
                       (*(ushort *)((int)param_1 + 0x1aa) & 0xfff) * 0x18 +
                       (uint)(byte)(&DAT_80111024)[uVar9] * 8);
  *(undefined1 *)((int)param_1 + 7) = 2;
  *(undefined1 *)((int)param_1 + 0x207) = 9;
switchD_80061694_caseD_2:
  uVar8 = *(ushort *)((int)param_1 + 0x1aa) & 0xfff;
  if (uVar8 == 0xf) {
    if ((uint)*(byte *)((int)param_1 + 0x1e9) % 3 == 0) {
      iVar4 = FUN_8008cea0(0xf,0);
      goto joined_r0x800617f8;
    }
LAB_80061800:
    DAT_800e112a = DAT_800e112a | 1;
    uVar3 = *(ushort *)((int)param_1 + 0x1aa) & 0xfff;
    FUN_8005ab48(param_1,(uVar3 - 1) * 0x10000 | uVar9,
                 &UNK_80110370 + uVar3 * 0x18 + (uint)(byte)(&DAT_80111024)[uVar9] * 8);
    FUN_80089d54(param_1,param_2,param_3,0x200);
    (*(code *)(&PTR_FUN_80111078)[(*(ushort *)((int)param_1 + 0x1aa) & 0xfff) - 1])(param_1);
    if ((param_4 & 0x100) == 0) {
      *(undefined2 *)((int)param_1 + 6) = 0x300;
      return;
    }
    if ((((param_4 & 0x10) == 0) && (DAT_800df8c1 < '\x1a')) || ((param_1[0x7c] & 0x80000000) != 0))
    {
      if ((((param_4 & 0x20) == 0) && (-0x1a < DAT_800df8c1)) || ((param_1[0x7c] & 0x20000000) != 0)
         ) {
        if ((((param_4 & 0x30) == 0) && (DAT_800df8c1 < '\x1a')) &&
           ((-0x1a < DAT_800df8c1 && ((param_1[0x7c] & 0x40000000) == 0)))) {
          *(undefined1 *)((int)param_1 + 7) = 1;
          *(ushort *)(param_1 + 0x7c) = *(ushort *)(param_1 + 0x7c) & 0x1fff | 0x4000;
          if ((*(ushort *)((int)param_1 + 0x1aa) & 0xfff) == 0x10) {
            FUN_80077adc(0x10d0001,param_1 + 10);
            return;
          }
          return;
        }
        if ((param_4 & 0x40) != 0) {
          if (((*(short *)(param_1 + 0x6a) != 0) &&
              (*(short *)(param_1 + 0x6a) < *(short *)((int)param_1 + 0x25e))) &&
             ((*(byte *)((int)param_1 + 0x1e9) & 3) == 0)) {
            FUN_8005c3e8(param_1);
          }
switchD_80061694_default:
          cVar7 = DAT_800df8c0;
          if (((param_4 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
            *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + -0x20;
          }
          if (((param_4 & 2) == 0) && (cVar7 < '\x1a')) {
            return;
          }
          *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x20;
          return;
        }
        goto LAB_80061a18;
      }
      *(undefined1 *)((int)param_1 + 7) = 1;
      uVar8 = *(ushort *)((int)param_1 + 0x1aa);
      uVar5 = *(ushort *)(param_1 + 0x7c) & 0x1fff | 0x2000;
    }
    else {
      *(undefined1 *)((int)param_1 + 7) = 1;
      uVar8 = *(ushort *)((int)param_1 + 0x1aa);
      uVar5 = *(ushort *)(param_1 + 0x7c) & 0x1fff | 0x8000;
    }
    *(ushort *)(param_1 + 0x7c) = uVar5;
    if ((uVar8 & 0xfff) == 0x10) {
      FUN_80077adc(0x10d0001,param_1 + 10);
      FUN_80052bd0(4,0);
      FUN_80052c6c(5,0xfa,0);
    }
  }
  else {
    iVar4 = FUN_8008cea0(uVar8,0);
joined_r0x800617f8:
    if (iVar4 != 0) goto LAB_80061800;
LAB_80061a18:
    *(undefined1 *)((int)param_1 + 7) = 3;
  }
  return;
}
