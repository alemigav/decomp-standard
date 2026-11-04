/* FUN_8009bb70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009bb70  body 0x8009bb70..0x8009bd83  size 532 B
 * body sha256 05e6c1f80829b207132da8d111ebc204a6bcb9611864863c6805e8fa4fb39d3f
 * provider record sha256 f87dbea482fa3974f35e498fbce8d6cd1f9deefa3876fdfba21eccf4b69f7a08
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8009bcb8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8009bb70(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  iVar1 = _DAT_8013a430;
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(_DAT_8013a430 + 0x288);
  *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(iVar1 + 0x28c);
  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(iVar1 + 0x290);
  iVar8 = param_1 + 0x78;
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(iVar1 + 0x294);
  *(undefined2 *)(param_1 + 0xd4) = *(undefined2 *)(iVar1 + 0x2a4);
  *(undefined2 *)(param_1 + 0xd6) = *(undefined2 *)(iVar1 + 0x2a6);
  iVar6 = 0;
  *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(iVar1 + 0x2ac);
  iVar5 = 0;
  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(iVar1 + 0x2a8);
  iVar1 = *(int *)(*(int *)(iVar1 + 0x294) + 8);
  *(undefined4 *)(param_1 + 0xdc) = 0xffffffff;
  *(int *)(param_1 + 0xd8) = iVar1 + param_2 * 0x10;
  iVar1 = iVar8;
  for (iVar7 = 0; iVar3 = 0, iVar7 < 3; iVar7 = iVar7 + 1) {
    iVar4 = iVar5;
    do {
      iVar2 = iVar8 + iVar3 + iVar6;
      *(char *)(iVar2 + 8) = (char)(*(ushort *)((int)&DAT_80131f84 + iVar4) >> 4);
      iVar3 = iVar3 + 1;
      *(char *)(iVar2 + 0xc) = (char)(*(ushort *)((int)&DAT_80131f84 + iVar4) >> 4);
      iVar4 = iVar4 + 6;
    } while (iVar3 < 3);
    fVar11 = (float)(int)*(short *)((int)&DAT_800e905c + iVar5);
    fVar10 = (float)(int)*(short *)((int)&DAT_800e9062 + iVar5);
    fVar12 = (float)(int)*(short *)((int)&DAT_800e9068 + iVar5);
    fVar9 = SQRT(fVar11 * fVar11 + fVar10 * fVar10 + fVar12 * fVar12);
    if (1.0 < fVar9) {
      fVar9 = 120.0 / fVar9;
    }
    else {
      fVar9 = 0.0;
    }
    iVar6 = iVar6 + 0x10;
    iVar5 = iVar5 + 2;
    *(char *)(iVar1 + 0x10) = (char)(int)(fVar9 * fVar11);
    *(char *)(iVar1 + 0x11) = (char)(int)(fVar9 * fVar10);
    *(char *)(iVar1 + 0x12) = (char)(int)(fVar9 * fVar12);
    iVar1 = iVar1 + 0x10;
    *(undefined1 *)(iVar8 + iVar7) = 0x7d;
    ((undefined1 *)(iVar8 + iVar7))[4] = 0x7d;
  }
  *(undefined4 *)(param_1 + 0xb0) = 3;
  return;
}
