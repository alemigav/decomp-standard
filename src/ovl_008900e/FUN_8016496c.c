/* FUN_8016496c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x8016496c  body 0x8016496c..0x80164d83  size 1048 B
 * body sha256 40649bd9027ebc733dff1222c707c031cee9b7da50f941ff93e60d56c25b549e
 * provider record sha256 2b06e9bf637a682f652cdd8342e911c295db44c48e88827e5eb22a2591b8345a
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016496c(uint *param_1)

{
  int iVar1;
  short sVar3;
  undefined *puVar2;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  _DAT_800df990 = FUN_80168448;
  param_1[0x7a] = 0x1000000;
  func_0x8008a994();
  uVar5 = param_1[0x8d];
  *(undefined1 *)((int)param_1 + 0x25d) = 8;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *param_1 = *param_1 | 0x2000000;
  *(undefined2 *)(uVar5 + 0xcf4) = 0x60;
  *(undefined2 *)(uVar5 + 0xcf6) = 0x60;
  *(undefined2 *)(uVar5 + 0xcf8) = 0x200;
  *(undefined2 *)(uVar5 + 0xcf0) = 0;
  *(undefined2 *)(uVar5 + 0xcf2) = 0;
  *(undefined2 *)(uVar5 + 0xcfa) = 0x138;
  uVar6 = param_1[0x8d];
  *(undefined4 *)(uVar6 + 0x2050) = 0;
  *(uint *)(uVar6 + 0x20b4) = param_1[0x8d] + 0xbf8;
  uVar5 = param_1[0x8d];
  *(undefined4 *)(uVar6 + 0x206c) = 0;
  *(undefined4 *)(uVar6 + 0x2070) = 0;
  *(undefined4 *)(uVar6 + 0x2074) = 0;
  *(undefined2 *)(uVar6 + 0x20a8) = 0x400;
  *(undefined2 *)(uVar6 + 0x20aa) = 0;
  *(undefined2 *)(uVar6 + 0x20ac) = 0x400;
  *(uint *)(uVar6 + 0x217c) = uVar5 + 0xbc0;
  func_0x80040e58(uVar6 + 0x20a8,uVar6 + 0x2058);
  DAT_80168d60 = 0;
  if ((_DAT_800e10ec & 0x20) == 0) {
    uVar5 = func_0x80033604();
    *(undefined2 *)((int)param_1 + 0x1f2) = *(undefined2 *)(&DAT_80168950 + (uVar5 & 0xf) * 2);
    iVar1 = func_0x800837ac(0x800e8ce0,0xa4);
    if (iVar1 != 0) {
      sVar3 = *(short *)((int)param_1 + 0x1f2) + -10;
      goto LAB_80164af4;
    }
  }
  else {
    uVar5 = func_0x80033604();
    *(undefined2 *)((int)param_1 + 0x1f2) = *(undefined2 *)(&DAT_80168970 + (uVar5 & 0xf) * 2);
    iVar1 = func_0x800837ac(0x800e8ce0,0xa4);
    if (iVar1 != 0) {
      sVar3 = *(short *)((int)param_1 + 0x1f2) + -0x14;
LAB_80164af4:
      *(short *)((int)param_1 + 0x1f2) = sVar3;
    }
  }
  *(undefined2 *)(param_1 + 0x77) = 0;
  *(undefined2 *)((int)param_1 + 0x1da) = 0;
  *(undefined2 *)(param_1 + 0x76) = 0;
  uVar6 = _DAT_800e9030;
  uVar5 = _DAT_800e902c;
  param_1[0x6e] = _DAT_800e9028;
  param_1[0x6f] = uVar5;
  param_1[0x70] = uVar6;
  uVar6 = _DAT_800e903c;
  uVar5 = _DAT_800e9038;
  param_1[0x71] = _DAT_800e9034;
  param_1[0x72] = uVar5;
  param_1[0x73] = uVar6;
  uVar5 = _DAT_800e9044;
  param_1[0x74] = _DAT_800e9040;
  param_1[0x75] = uVar5;
  param_1[0xb1] = 0x800e1130;
  *(undefined2 *)(param_1 + 0xae) = 0x44c;
  *(undefined2 *)((int)param_1 + 0x2ba) = 0x352;
  *(undefined2 *)((int)param_1 + 0x2d6) = 0xfe0c;
  param_1[1] = 0x1000000;
  *(undefined2 *)((int)param_1 + 0x1f6) = 0;
  *(undefined2 *)(param_1 + 0x7d) = 0;
  param_1[0xaf] = 0;
  *(undefined1 *)((int)param_1 + 0x2b5) = 0;
  *(undefined2 *)(param_1 + 0xb2) = 0;
  *(undefined1 *)((int)param_1 + 0x2ca) = 0;
  *(undefined1 *)((int)param_1 + 0x2b6) = 0;
  *(undefined1 *)((int)param_1 + 0x2b7) = 0;
  *(undefined1 *)((int)param_1 + 0x2cf) = 0;
  param_1[0xb6] = 0;
  *param_1 = *param_1 & 0xfffffff5;
  if ((*(ushort *)((int)param_1 + 0x1aa) & 0x4000) == 0) {
    puVar2 = &DAT_80168be4;
  }
  else {
    puVar2 = &DAT_80168be8;
  }
  *(undefined *)((int)param_1 + 5) = puVar2[*(ushort *)((int)param_1 + 0x1aa) & 0xf];
  DAT_80168d5c = 0;
  DAT_80168d5a = 0;
  DAT_80168d58 = 0;
  switch(*(ushort *)((int)param_1 + 0x1aa) >> 8 & 0xf) {
  case 0:
    goto LAB_80164ccc;
  case 1:
    DAT_80168d5c = 0x400;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    *param_1 = *param_1 | 8;
    FUN_80162a30(param_1);
    goto switchD_80164c1c_default;
  case 2:
    DAT_80168d5c = 0xfc00;
    uVar4 = 2;
    break;
  case 3:
    DAT_80168d58 = 0xfc00;
    uVar4 = 3;
    break;
  case 4:
    DAT_80168d58 = 0x400;
    uVar4 = 1;
    break;
  case 5:
    DAT_80168d58 = 0x800;
    DAT_80168d5a = 0x800;
LAB_80164ccc:
    FUN_801629c0(param_1);
  default:
    goto switchD_80164c1c_default;
  }
  *(undefined1 *)((int)param_1 + 0x207) = uVar4;
  FUN_80162a30(param_1);
  *param_1 = *param_1 | 8;
switchD_80164c1c_default:
  *param_1 = *param_1 & 0xe3ffffff | 0xc000000;
  func_0x800339dc(param_1 + 0x82,0,
                  CONCAT22(*(undefined2 *)((int)param_1 + 0x2ba),*(undefined2 *)(param_1 + 0xae)),0,
                  param_1[0x8d] + 0x33c);
  *(undefined2 *)param_1[0x82] = 0xfa;
  uVar5 = param_1[0x8d];
  *(uint *)(uVar5 + 0x4c) = param_1[10];
  *(uint *)(uVar5 + 0x50) = param_1[0xb];
  *(uint *)(uVar5 + 0x54) = param_1[0xc];
  uVar5 = param_1[0x8d];
  *(uint *)(uVar5 + 0x1c4) = param_1[10];
  *(uint *)(uVar5 + 0x1c8) = param_1[0xb];
  *(uint *)(uVar5 + 0x1cc) = param_1[0xc];
  param_1[0xa8] = (uint)FUN_8016257c;
  return;
}
