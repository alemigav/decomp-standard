/* FUN_8016fe30
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8016fe30  body 0x8016fe30..0x801700ab  size 636 B
 * body sha256 9da8c820b27c407bfe604ab665c796c0bea546d45b85990c6d628006655f6f7b
 * provider record sha256 8aa90ecfe488103b9e4c6d0169ffa01adacae7b7ad849615fb2a6ba05ea075cf
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8016ff20) */
/* WARNING: Removing unreachable block (ram,0x8016ffc4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016fe30(void)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  undefined4 local_78;
  short local_74;
  short local_72;
  undefined1 local_70;
  undefined1 local_6f;
  short local_6e;
  short local_6c;
  short local_6a;
  char local_68;
  undefined1 local_67;
  ushort local_66;
  short local_64;
  short local_62;
  undefined1 local_60;
  char local_5f;
  undefined2 local_5e;
  short local_5c;
  short local_5a;
  char local_58;
  char local_57;
  undefined *local_54;
  short local_50 [12];
  short local_38 [12];
  
  local_50[0] = 0xc3;
  local_50[1] = 0xd1;
  local_50[2] = 0xdf;
  local_50[3] = 0xe9;
  local_50[4] = 0xf7;
  local_50[5] = 0x105;
  local_50[6] = 0x10f;
  local_50[7] = 0x11d;
  local_50[8] = 0xe9;
  local_50[9] = 0xf7;
  local_38[0] = 0x8c;
  local_38[1] = 0x8c;
  local_38[2] = 0x8c;
  local_38[3] = 0x8c;
  local_38[4] = 0x8c;
  local_38[5] = 0x8c;
  local_38[6] = 0x8c;
  local_38[7] = 0x8c;
  local_38[8] = 0xac;
  local_38[9] = 0xac;
  local_5e = 0;
  iVar1 = 10;
  do {
    iVar4 = iVar1 + -1;
    func_0x80043620();
    iVar1 = (uint)(byte)(&UNK_8017236b)[iVar1] * 10;
    psVar3 = local_50 + iVar4;
    psVar2 = local_38 + iVar4;
    local_68 = (&DAT_80171874)[iVar1] + (&DAT_80171876)[iVar1];
    local_5f = (&DAT_80171875)[iVar1] + (&DAT_80171877)[iVar1];
    local_6c = *psVar3 + (ushort)(byte)(&DAT_80171878)[iVar1];
    local_62 = *psVar2 + (ushort)(byte)(&DAT_80171879)[iVar1];
    local_74 = *psVar3;
    local_72 = *psVar2;
    local_70 = (&DAT_80171874)[iVar1];
    local_6f = (&DAT_80171875)[iVar1];
    local_6e = *(short *)(&DAT_80171872 + iVar1) << 3;
    local_6a = *psVar2;
    local_67 = (&DAT_80171875)[iVar1];
    local_66 = *(short *)(&DAT_80171870 + iVar1) + 0x80;
    local_64 = *psVar3;
    local_60 = (&DAT_80171874)[iVar1];
    local_54 = (&PTR_DAT_80171cc8)[(int)(local_66 - 0x88) >> 1];
    local_78 = 4;
    local_5c = local_6c;
    local_5a = local_62;
    local_58 = local_68;
    local_57 = local_5f;
    _DAT_800df8b4 = func_0x80044fdc(_DAT_800df8b4,&local_78,0);
    iVar1 = iVar4;
  } while (iVar4 != 0);
  return;
}
