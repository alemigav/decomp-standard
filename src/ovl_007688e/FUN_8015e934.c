/* FUN_8015e934
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015e934  body 0x8015e934..0x8015ec3f  size 780 B
 * body sha256 a4ef84bfd1ae884fde097a49242e55c95febe688eddf95ee5d65edd3c80ed77a
 * provider record sha256 14753623d03f72151a6c282f12546d369d454f8625e34e987ea7d16ee802df8b
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8015ea9c) */
/* WARNING: Removing unreachable block (ram,0x8015ea3c) */
/* WARNING: Removing unreachable block (ram,0x8015eb34) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8015e934(int param_1)

{
  int iVar1;
  char cVar2;
  ushort *puVar3;
  uint in_t2;
  uint uVar4;
  
  uVar4 = 0;
  puVar3 = &DAT_80160bf8;
  do {
    cVar2 = DAT_80160c27;
    iVar1 = (uint)*puVar3 * 0x28;
    (&DAT_80160c3a)[iVar1] = DAT_80160c27;
    (&DAT_80160c39)[iVar1] = cVar2;
    (&DAT_80160c38)[iVar1] = cVar2;
    uVar4 = uVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar4 < 3);
  if (param_1 == 0) {
    if (DAT_8016150c == 0) {
      *(undefined2 *)(&DAT_80160e72 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
      *(undefined2 *)(&DAT_80160d82 + (uint)DAT_800dfbe8 * 0x14) = 0;
      in_t2 = 0;
    }
    else if (DAT_8016150c == 1) {
      *(undefined2 *)(&DAT_80160d82 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
      *(undefined2 *)(&DAT_80160e72 + (uint)DAT_800dfbe8 * 0x14) = 0;
      in_t2 = 2;
    }
    *(undefined2 *)(&DAT_801610f2 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
  }
  else {
    *(undefined2 *)(&DAT_80160d82 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_80160e72 + (uint)DAT_800dfbe8 * 0x14) = 0x100;
    *(undefined2 *)(&DAT_801610f2 + (uint)DAT_800dfbe8 * 0x14) = 0;
    in_t2 = 4;
  }
  uVar4 = 0;
  iVar1 = (uint)*(ushort *)((int)&DAT_80160bf8 + (in_t2 & 0xfffffffe)) * 0x28;
  cVar2 = DAT_80160c27 + DAT_80160c23;
  (&DAT_80160c3a)[iVar1] = cVar2;
  (&DAT_80160c39)[iVar1] = cVar2;
  (&DAT_80160c38)[iVar1] = cVar2;
  do {
    _DAT_800df8b4 =
         func_0x80043988(_DAT_800df8b4,&DAT_80160c38 + (uint)(ushort)(&DAT_80160bf8)[uVar4] * 0x28,0
                         ,0);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 3);
  return;
}
