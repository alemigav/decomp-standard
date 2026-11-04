/* FUN_80170104
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x80170104  body 0x80170104..0x801707d7  size 1748 B
 * body sha256 e36416b4155d1087017184d37603b08c5fd51ee6b2157b27dcc11793f6612cac
 * provider record sha256 9ff475a578eb2055018e9c48873f059a0af5b6e773e34490e60b54d708d4496d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x801706d8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80170104(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort uVar6;
  uint uVar7;
  ushort local_18 [8];
  
  local_18[0] = 0x10d;
  local_18[1] = 199;
  local_18[2] = 0x90;
  local_18[3] = 99;
  local_18[4] = 0;
  iVar2 = func_0x8006bb0c(0xffffffff);
  uVar7 = (_DAT_800e8b30 + iVar2) - _DAT_800dfbe4;
  uVar3 = uVar7 / 0x34bc0;
  DAT_80171de1 = (char)uVar3;
  if ((uVar3 & 0xff) == 0) {
    DAT_8017236c = '\x17';
LAB_801701fc:
    DAT_8017236d = DAT_8017236c;
  }
  else {
    if (0x62 < (uVar3 & 0xff)) {
      DAT_8017236c = ' ';
      goto LAB_801701fc;
    }
    cVar1 = (char)((uVar3 & 0xff) / 10);
    DAT_8017236c = cVar1 + '\x17';
    DAT_8017236d = DAT_80171de1 + cVar1 * -10 + '\x17';
  }
  DAT_8017236e = 0x24;
  DAT_80172371 = 0x24;
  uVar3 = (uVar7 % 0x34bc0) / 0xe10;
  DAT_80171de2 = (char)uVar3;
  DAT_80171de4 = DAT_80171ea0._1_1_;
  uVar4 = (uVar7 % 0xe10) / 0x3c;
  DAT_80171de3 = (char)uVar4;
  cVar1 = (char)(uVar3 / 10);
  DAT_8017236f = cVar1 + '\x17';
  DAT_80172370 = DAT_80171de2 + cVar1 * -10 + '\x17';
  cVar1 = (char)(uVar4 / 10);
  DAT_80172372 = cVar1 + '\x17';
  DAT_80172373 = DAT_80171de3 + cVar1 * -10 + '\x17';
  if (DAT_80171ea0._1_1_ < 99) {
    DAT_80172374 = DAT_80171ea0._1_1_ / 10 + 0x17;
    DAT_80172375 = DAT_80171ea0._1_1_ % 10 + 0x17;
  }
  else {
    DAT_80172374 = ' ';
    DAT_80172375 = ' ';
  }
  uVar3 = 540000;
  uVar4 = 0;
  if (540000 < uVar7) {
    for (uVar4 = 1; uVar3 = uVar3 + 0x34bc0, uVar4 < 10; uVar4 = uVar4 + 1) {
      if (uVar7 <= uVar3) goto LAB_801703b4;
    }
    uVar4 = 10;
  }
LAB_801703b4:
  DAT_80171dde = (char)uVar4 * -10 + 100;
  if (DAT_80171ea0._0_2_ < 0x14) {
    DAT_80171ddf = DAT_80171ea0._1_1_ * -5 + 100;
  }
  else {
    DAT_80171ddf = 0;
  }
  if (DAT_80171e9c._2_2_ < 6) {
    DAT_80171de0 = (char)DAT_80171e9c._2_2_ * -0xf + 100;
  }
  else {
    DAT_80171de0 = 0;
  }
  DAT_80171ddc = (ushort)DAT_80171de0 + (ushort)DAT_80171dde + (ushort)DAT_80171ddf;
  if ((_DAT_800e110c & 0x800000) != 0) {
    if (DAT_80171ddc < 0x32) {
      DAT_80171ddc = 0;
    }
    else {
      DAT_80171ddc = DAT_80171ddc - 0x32;
    }
  }
  uVar6 = 0;
  puVar5 = local_18;
  if (DAT_80171ddc < local_18[0]) {
    do {
      puVar5 = puVar5 + 1;
      uVar6 = uVar6 + 1;
    } while (DAT_80171ddc < *puVar5);
  }
  DAT_80171ddc = uVar6;
  if ((_DAT_800e110c & 0x4000000) != 0) {
    DAT_8017236e = 0x24;
    DAT_80172371 = 0x24;
    return;
  }
  if ((DAT_80171dde == 100) && (DAT_80171ddc < 2)) {
    iVar2 = FUN_801707d8(0x11);
    if (iVar2 != 0) goto LAB_8017056c;
    DAT_80171b98 = 0x808080;
    DAT_80171df4 = DAT_80171df4 | 0xa0;
  }
  else {
    iVar2 = FUN_801707d8(0x11);
    if (iVar2 != 0) {
LAB_8017056c:
      DAT_80171b98 = 0;
      DAT_80171df4 = DAT_80171df4 | 0x20;
    }
  }
  if ((_DAT_800e110c & 0x40000000) == 0) {
    iVar2 = FUN_801707d8(0xf);
    if (iVar2 != 0) {
      DAT_80171b8c = 0;
      DAT_80171df4 = DAT_80171df4 | 0x10;
    }
    iVar2 = FUN_801707d8(0x12);
    if (iVar2 != 0) {
      DAT_80171ba4 = 0;
      DAT_80171df4 = DAT_80171df4 | 0x40;
    }
    iVar2 = func_0x800837ac(&DAT_80172098,0x9c);
    if (iVar2 == 0) {
      func_0x80083758(&DAT_80172208,0x12);
      return;
    }
    return;
  }
  if ((DAT_80171de0 == 100) && (DAT_80171ddc < 2)) {
    iVar2 = FUN_801707d8(0xf);
    if (iVar2 != 0) goto LAB_8017060c;
    DAT_80171b8c = 0x808080;
    DAT_80171df4 = DAT_80171df4 | 0x90;
  }
  else {
    iVar2 = FUN_801707d8(0xf);
    if (iVar2 != 0) {
LAB_8017060c:
      DAT_80171b8c = 0;
      DAT_80171df4 = DAT_80171df4 | 0x10;
    }
  }
  if ((DAT_80171ddf == 100) && (DAT_80171ddc < 2)) {
    iVar2 = FUN_801707d8(0x12);
    if (iVar2 == 0) {
      DAT_80171ba4 = 0x808080;
      DAT_80171df4 = DAT_80171df4 | 0xc0;
      goto LAB_8017069c;
    }
  }
  else {
    iVar2 = FUN_801707d8(0x12);
    if (iVar2 == 0) goto LAB_8017069c;
  }
  DAT_80171ba4 = 0;
  DAT_80171df4 = DAT_80171df4 | 0x40;
LAB_8017069c:
  iVar2 = func_0x800837ac(&DAT_80172208,0x13);
  if (iVar2 == 0) {
    if (DAT_80171ddc == 0) {
      func_0x80083758(&DAT_80172208,0x13);
      DAT_80171df4 = DAT_80171df4 | 0x100;
    }
  }
  else {
    func_0x800837ac(&DAT_80172208,0x14);
  }
  iVar2 = func_0x800837ac(&DAT_80172098,0x9c);
  if ((iVar2 == 0) && (iVar2 = func_0x800837ac(&DAT_80172208,0x12), iVar2 != 0)) {
    DAT_80171df4 = DAT_80171df4 | 0x400;
  }
  return;
}
