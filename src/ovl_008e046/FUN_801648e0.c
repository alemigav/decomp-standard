/* FUN_801648e0
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801648e0  body 0x801648e0..0x80164cff  size 1056 B
 * body sha256 1bd249e94bbeef1aa32ddf39aa803f2b9a2551d8fa643b3ba9cff2f539e56339
 * provider record sha256 49375b243ffbeeec50142463d6d2ed52c15c027b2246e3e79d0213daedc920de
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801648e0(uint *param_1)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  undefined1 uVar4;
  uint uVar5;
  
  param_1[0x7a] = 0x1000000;
  func_0x80089d54();
  _DAT_800df998 = FUN_80166d84;
  *(undefined2 *)(param_1 + 0x9b) = 0;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  *(undefined2 *)(param_1 + 0x9a) = 0;
  *(undefined2 *)(param_1 + 0x99) = 0;
  *param_1 = *param_1 | 0x1c000000;
  if ((_DAT_800e10ec & 0x20) == 0) {
    uVar1 = func_0x80033604();
    *(undefined2 *)((int)param_1 + 0x1f2) = *(undefined2 *)(&DAT_80167174 + (uVar1 & 0xf) * 2);
    iVar2 = func_0x800837ac(0x800e8ce0,0xa4);
    if (iVar2 != 0) {
      sVar3 = *(short *)((int)param_1 + 0x1f2) + -0x1e;
      goto LAB_801649dc;
    }
  }
  else {
    uVar1 = func_0x80033604();
    *(undefined2 *)((int)param_1 + 0x1f2) = *(undefined2 *)(&DAT_80167154 + (uVar1 & 0xf) * 2);
    iVar2 = func_0x800837ac(0x800e8ce0,0xa4);
    if (iVar2 != 0) {
      sVar3 = *(short *)((int)param_1 + 0x1f2) + -0x28;
LAB_801649dc:
      *(short *)((int)param_1 + 0x1f2) = sVar3;
    }
  }
  uVar1 = param_1[0x8d];
  *(undefined1 *)((int)param_1 + 0x25d) = 8;
  *(undefined1 *)(param_1 + 0x97) = 0;
  *param_1 = *param_1 | 0x2000000;
  *(undefined2 *)(uVar1 + 0xcf4) = 0x60;
  *(undefined2 *)(uVar1 + 0xcf6) = 0x60;
  *(undefined2 *)(uVar1 + 0xcf8) = 0x200;
  *(undefined2 *)(uVar1 + 0xcf0) = 0;
  *(undefined2 *)(uVar1 + 0xcf2) = 0;
  *(undefined2 *)(uVar1 + 0xcfa) = 0x138;
  uVar5 = param_1[0x8d];
  *(undefined4 *)(uVar5 + 0x2050) = 0;
  *(uint *)(uVar5 + 0x20b4) = param_1[0x8d] + 0xbf8;
  uVar1 = param_1[0x8d];
  *(undefined4 *)(uVar5 + 0x206c) = 0;
  *(undefined4 *)(uVar5 + 0x2070) = 0;
  *(undefined4 *)(uVar5 + 0x2074) = 0;
  *(undefined2 *)(uVar5 + 0x20a8) = 0x400;
  *(undefined2 *)(uVar5 + 0x20aa) = 0;
  *(undefined2 *)(uVar5 + 0x20ac) = 0x400;
  *(uint *)(uVar5 + 0x217c) = uVar1 + 0xbc0;
  func_0x80040e58(uVar5 + 0x20a8,uVar5 + 0x2058);
  DAT_80167540 = 0;
  *(undefined2 *)(param_1 + 0x77) = 0;
  *(undefined2 *)((int)param_1 + 0x1da) = 0;
  *(undefined2 *)(param_1 + 0x76) = 0;
  uVar5 = _DAT_800e9030;
  uVar1 = _DAT_800e902c;
  param_1[0x6e] = _DAT_800e9028;
  param_1[0x6f] = uVar1;
  param_1[0x70] = uVar5;
  uVar5 = _DAT_800e903c;
  uVar1 = _DAT_800e9038;
  param_1[0x71] = _DAT_800e9034;
  param_1[0x72] = uVar1;
  param_1[0x73] = uVar5;
  uVar1 = _DAT_800e9044;
  param_1[0x74] = _DAT_800e9040;
  param_1[0x75] = uVar1;
  param_1[0xb1] = 0x800e1130;
  *(undefined2 *)(param_1 + 0xae) = 0x44c;
  *(undefined2 *)((int)param_1 + 0x2ba) = 0x352;
  *(undefined2 *)((int)param_1 + 0x2d6) = 0xfe0c;
  param_1[1] = 0x1000000;
  *(undefined2 *)(param_1 + 0x9c) = 0;
  *(undefined2 *)((int)param_1 + 0x272) = 0;
  *(undefined2 *)(param_1 + 0x9d) = 0;
  *(undefined2 *)((int)param_1 + 0x276) = 0;
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
  *(undefined *)((int)param_1 + 5) = (&DAT_801671c0)[*(ushort *)((int)param_1 + 0x1aa) & 0xf];
  DAT_8016753c = 0;
  DAT_8016753a = 0;
  DAT_80167538 = 0;
  switch(*(ushort *)((int)param_1 + 0x1aa) >> 8 & 0xf) {
  case 0:
    goto LAB_80164c4c;
  case 1:
    DAT_8016753c = 0x400;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    *param_1 = *param_1 | 8;
    FUN_80162a30(param_1);
    goto switchD_80164b9c_default;
  case 2:
    DAT_8016753c = 0xfc00;
    uVar4 = 2;
    break;
  case 3:
    DAT_80167538 = 0xfc00;
    uVar4 = 3;
    break;
  case 4:
    DAT_80167538 = 0x400;
    uVar4 = 1;
    break;
  case 5:
    DAT_80167538 = 0x800;
    DAT_8016753a = 0x800;
LAB_80164c4c:
    FUN_801629c0(param_1);
  default:
    goto switchD_80164b9c_default;
  }
  *(undefined1 *)((int)param_1 + 0x207) = uVar4;
  FUN_80162a30(param_1);
  *param_1 = *param_1 | 8;
switchD_80164b9c_default:
  *param_1 = *param_1 & 0xe3ffffff | 0xc000000;
  func_0x800339dc(param_1 + 0x82,0,
                  CONCAT22(*(undefined2 *)((int)param_1 + 0x2ba),*(undefined2 *)(param_1 + 0xae)),0,
                  param_1[0x8d] + 0x33c);
  *(undefined2 *)param_1[0x82] = 0xfa;
  uVar1 = param_1[0x8d];
  *(uint *)(uVar1 + 0x4c) = param_1[10];
  *(uint *)(uVar1 + 0x50) = param_1[0xb];
  *(uint *)(uVar1 + 0x54) = param_1[0xc];
  uVar1 = param_1[0x8d];
  *(uint *)(uVar1 + 0x1c4) = param_1[10];
  *(uint *)(uVar1 + 0x1c8) = param_1[0xb];
  *(uint *)(uVar1 + 0x1cc) = param_1[0xc];
  param_1[0xa8] = (uint)FUN_8016257c;
  return;
}
