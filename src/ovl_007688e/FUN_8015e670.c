/* FUN_8015e670
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015e670  body 0x8015e670..0x8015e933  size 708 B
 * body sha256 9ccf002900def7b7d5799b9e931f5e5e251f5acb0f4660dd7c250fbbc396d5ce
 * provider record sha256 abdd086f0ec010ef26a6685dc21e9a197c28005e56c8423a8065ecc73fb64a28
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8015e758) */
/* WARNING: Removing unreachable block (ram,0x8015e7b8) */
/* WARNING: Removing unreachable block (ram,0x8015e850) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015e670(int param_1)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  iVar4 = 0x1a;
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
    bVar1 = DAT_80160c29 != '\x01';
    if (bVar1) {
      *(undefined2 *)(&DAT_801610a2 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
      *(undefined2 *)(&DAT_80161052 + (uint)DAT_800dfbe8 * 0x14) = 0;
    }
    else {
      *(undefined2 *)(&DAT_80161052 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
      *(undefined2 *)(&DAT_801610a2 + (uint)DAT_800dfbe8 * 0x14) = 0;
    }
    uVar5 = (uint)!bVar1;
    *(undefined2 *)(&DAT_801610f2 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
  }
  else {
    *(undefined2 *)(&DAT_80161052 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_801610a2 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_801610f2 + (uint)DAT_800dfbe8 * 0x14) = 0;
    uVar5 = 2;
  }
  iVar4 = uVar5 * 0x50;
  uVar5 = 0;
  iVar2 = 0x1a;
  cVar3 = DAT_80160c27 + DAT_80160c23;
  (&DAT_8016104a)[iVar4] = cVar3;
  (&DAT_80161049)[iVar4] = cVar3;
  (&DAT_80161048)[iVar4] = cVar3;
  do {
    _DAT_800df8b4 = func_0x80043988(_DAT_800df8b4,&DAT_80160c38 + iVar2 * 0x28,0,0);
    uVar5 = uVar5 + 1;
    iVar2 = iVar2 + 2;
  } while (uVar5 < 3);
  return;
}
