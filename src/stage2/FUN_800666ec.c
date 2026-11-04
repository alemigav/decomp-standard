/* FUN_800666ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800666ec  body 0x800666ec..0x800667ab  size 192 B
 * body sha256 b736ec0f45a8150ee95803109eb304e5525c7d45060b42490cfd8e337f4ed298
 * provider record sha256 75d5c9c2962eb0dd182f816778db63463f45b16324135f52d11f356732c5a486
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800666ec(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = 1;
  iVar1 = *(int *)(param_1 + 600);
  iVar3 = *param_4;
  FUN_80065f50(param_2);
  uVar2 = param_4[1];
  uVar6 = (uint)*(ushort *)((int)param_4 + 10);
  uVar4 = uVar2 >> 1;
  do {
    if (*(short *)(param_4 + iVar5 + 2) != 0) {
      FUN_80066048(param_2,iVar3 + iVar1 + uVar4 * 2,0x1000 - *(short *)(param_4 + iVar5 + 2));
    }
    uVar4 = uVar4 + (uVar2 >> 1);
    uVar6 = uVar6 - 1;
    iVar5 = iVar5 + 1;
  } while (uVar6 != 0);
  return;
}
