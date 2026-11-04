/* FUN_8009b27c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b27c  body 0x8009b27c..0x8009b66f  size 1012 B
 * body sha256 f1ae1507f6544104a266d7eae42bfd321aa4004bb9a88afeecb48ddc85555850
 * provider record sha256 fa6ca78422fb2c4239b0086bf350af1fed33f73274c35f1f1518373e7859bc05
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8009b548) */
/* WARNING: Removing unreachable block (ram,0x8009b3c8) */
/* WARNING: Removing unreachable block (ram,0x8009b444) */
/* WARNING: Removing unreachable block (ram,0x8009b648) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009b27c(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar5 = 0;
  piVar6 = (int *)&DAT_80132118;
  local_2c = 10000;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  _DAT_8013a430 = DAT_800c52dc + 0x40807U & 0xfffffff8;
  DAT_800e10ec = DAT_800e10ec | 0x2000000;
  DAT_801320fc = _DAT_8013a430 + 0x2f0;
  do {
    iVar5 = iVar5 + 1;
    *piVar6 = DAT_801320fc;
    puVar3 = DAT_80132118;
    DAT_801320fc = DAT_801320fc + 0x1e8;
    piVar6 = piVar6 + 1;
  } while (iVar5 < 10);
  if (DAT_80132118 < (undefined2 *)0x1e3) {
    *DAT_80132118 = 0;
    while (puVar3 = puVar3 + 1, puVar3 < (undefined2 *)0x1e3) {
      *puVar3 = 0;
    }
  }
  *(int *)(_DAT_8013a430 + 0x294) = DAT_801320fc;
  iVar5 = func_0x80004cfc(*(undefined2 *)(&DAT_80132018 + (uint)*(byte *)(DAT_800dfb58 + 0xc) * 2),
                          *(undefined4 *)(_DAT_8013a430 + 0x294),0,"DOOR_MDL");
  DAT_801320fc = DAT_801320fc + iVar5;
  FUN_800824b8(*(undefined4 *)(_DAT_8013a430 + 0x294));
  uVar1 = *(undefined2 *)(&DAT_80132088 + (uint)*(byte *)(DAT_800dfb58 + 0xc) * 2);
  FUN_80087868(_DAT_8013a430 + 0x248,uVar1);
  DAT_80132100 = DAT_801320fc;
  DAT_801320fc = FUN_800874d4(DAT_801320fc,_DAT_8013a430 + 0x288,_DAT_8013a430 + 0x28c,uVar1,
                              _DAT_8013a430 + 0x248);
  uVar2 = _DAT_8013a430;
  iVar5 = 10;
  puVar4 = &DAT_80114958;
  DAT_80132104 = DAT_801320fc;
  *(undefined4 *)(_DAT_8013a430 + 8) = 3;
  *(undefined4 *)(uVar2 + 0xc) = 0x140;
  *(undefined4 *)(uVar2 + 0x10) = 0xf0;
  *(undefined2 *)(uVar2 + 0x22a) = 0;
  do {
    puVar4[3] = (char)iVar5;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[4] = 0xff;
    puVar4[8] = 0xff;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 0x174;
  } while (iVar5 < 0xe);
  DAT_80114f2c = DAT_800c52dc + 0x3b800;
  func_0x80004cfc(*(undefined2 *)(&DAT_80131fa8 + (uint)*(byte *)(DAT_800dfb58 + 0xc) * 2),
                  DAT_80114f2c,0,"DOOR_SCD");
  FUN_8006d5dc(&DAT_80114958,0);
  FUN_800428e0(0x122);
  FUN_800828ac(&local_2c,&local_20);
  *(undefined4 *)(_DAT_8013a430 + 0x2ac) = 0xffffffff;
  FUN_800274e4(4,1);
  FUN_80026980(0xc);
  DAT_800e90f8 = 1;
  FUN_8004cd88();
  DAT_800e8c92 = 0;
  DAT_800e8c90 = *(byte *)(DAT_800dfb58 + 0xd) & 0xff7f;
  DAT_800e8c94 = *(byte *)(DAT_800dfb58 + 0xd) & 0x80;
  DAT_800e8c96 = (ushort)*(byte *)(DAT_800dfb58 + 0xc);
  *(undefined2 *)(_DAT_8013a430 + 0x244) = 0;
  return;
}
