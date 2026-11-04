/* FUN_80074fbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074fbc  body 0x80074fbc..0x800750ab  size 240 B
 * body sha256 43a22635e784f56ad8ff82820bf59181289460109a0b069cf2bb9e0544c3afa9
 * provider record sha256 9c1ab8d48f6a3f2341ddd379285f940835532e0bfc4b8556e4a334281fc2d54a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80074fbc(int param_1)

{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = DAT_80115423 + 1 & 0xf;
  iVar5 = uVar3 * 2;
  DAT_80115423 = (byte)uVar3;
  if (param_1 == 1) {
    puVar2 = &DAT_801153e0;
    bVar1 = (&DAT_801153e0)[iVar5];
  }
  else {
    puVar2 = &DAT_80115400;
    bVar1 = (&DAT_80115400)[iVar5];
  }
  iVar4 = DAT_800e9250 * 0x28;
  FUN_8006cdf0(*(undefined4 *)(&DAT_800c4f80 + iVar4),*(undefined4 *)(&DAT_800c4f84 + iVar4),
               *(undefined4 *)(&DAT_800c4f88 + iVar4),*(undefined4 *)(&DAT_800c4f8c + iVar4),
               *(undefined4 *)(&DAT_800c4f90 + iVar4),*(undefined4 *)(&DAT_800c4f94 + iVar4),
               *(int *)(&DAT_800c4f98 + iVar4) - (uint)bVar1,
               *(int *)(&DAT_800c4f9c + iVar4) - (uint)bVar1,
               *(int *)(&DAT_800c4fa0 + iVar4) - (uint)(byte)puVar2[iVar5 + 1],
               *(int *)(&DAT_800c4fa4 + iVar4) - (uint)(byte)puVar2[iVar5 + 1],0,0);
  return;
}
