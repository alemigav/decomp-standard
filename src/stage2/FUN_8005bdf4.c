/* FUN_8005bdf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005bdf4  body 0x8005bdf4..0x8005be9f  size 172 B
 * body sha256 aa12037cfd412ff96637cad91c4b863496261b407ff7d372fe708ccd0cd20fc1
 * provider record sha256 67bdd1ded649d504b88de7636ce39d57c0fb1ab580431ee04710dd9d42089674
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005bdf4(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *param_1;
  iVar4 = (param_3 << 0x10) >> 0xd;
  *param_1 = uVar1 & 0x1fffffff;
  iVar3 = (int)(((int)*(short *)(&DAT_80110e74 +
                                ((char)(&DAT_80110f04)[*(byte *)(param_1 + 2)] + 2) * 2 + iVar4) +
                param_1[0xb]) * (int)*(short *)((int)param_1 + 0x27a)) >> 0xc;
  uVar2 = 0x80000000;
  if ((iVar3 + *(short *)(&DAT_80110e74 + iVar4) <= param_2) &&
     (uVar2 = 0x20000000, param_2 <= iVar3 + *(short *)(&DAT_80110e76 + iVar4))) {
    uVar2 = 0x40000000;
  }
  *param_1 = uVar1 & 0x1fffffff | uVar2;
  return;
}
