/* FUN_8015f550
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015f550  body 0x8015f550..0x8015f817  size 712 B
 * body sha256 8592eea1d61ba3355cf5aa2fc44f6b5e9e9be7e4c6b4b2aa36c89a22bbf762ca
 * provider record sha256 066bdab8926ddc47dcbb7415f1f4271812e7852cf9a593e53fb203bd4110c0e9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8015f638) */
/* WARNING: Removing unreachable block (ram,0x8015f680) */
/* WARNING: Removing unreachable block (ram,0x8015f734) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015f550(int param_1)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  iVar4 = 0x20;
  do {
    cVar3 = DAT_80160c27;
    iVar2 = iVar4 * 0x28;
    (&DAT_80160c3a)[iVar2] = DAT_80160c27;
    (&DAT_80160c39)[iVar2] = cVar3;
    (&DAT_80160c38)[iVar2] = cVar3;
    uVar5 = uVar5 + 1;
    iVar4 = iVar4 + 2;
  } while (uVar5 < 3);
  if (param_1 == 0) {
    bVar1 = DAT_800dfbe9 == '\0';
    if (bVar1) {
      *(undefined2 *)(&DAT_80161142 + (uint)DAT_800dfbe8 * 0x14) = 0;
      *(undefined2 *)(&DAT_80161192 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    }
    else {
      *(undefined2 *)(&DAT_80161142 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
      *(undefined2 *)(&DAT_80161192 + (uint)DAT_800dfbe8 * 0x14) = 0;
    }
    uVar5 = (uint)!bVar1;
    *(undefined2 *)(&DAT_801611e2 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
  }
  else {
    *(undefined2 *)(&DAT_80161142 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_80161192 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_801611e2 + (uint)DAT_800dfbe8 * 0x14) = 0;
    uVar5 = 2;
  }
  iVar4 = uVar5 * 0x50;
  uVar5 = 0;
  iVar2 = 0x20;
  cVar3 = DAT_80160c27 + DAT_80160c23;
  (&DAT_8016113a)[iVar4] = cVar3;
  (&DAT_80161139)[iVar4] = cVar3;
  (&DAT_80161138)[iVar4] = cVar3;
  do {
    _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,&DAT_80160c38 + iVar2 * 0x28,0,0);
    uVar5 = uVar5 + 1;
    iVar2 = iVar2 + 2;
  } while (uVar5 < 3);
  return;
}
