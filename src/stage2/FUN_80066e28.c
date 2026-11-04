/* FUN_80066e28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80066e28  body 0x80066e28..0x80066ec7  size 160 B
 * body sha256 e862cfe7a63104c16ad8b75298ae9066700ff922f6318855838156c0e2fe26c8
 * provider record sha256 3a1eb36dbc1b54e3fd3ccb98c0e7b4b58b0fcba8bdfdb0498839341a06100463
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80066e28(int param_1,int param_2,short *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (((uint)(ushort)param_3[2] + (int)*param_3 + (uint)*(ushort *)(param_1 + 300)) -
          *(int *)(param_1 + 0x120)) + 1;
  iVar1 = (((int)*param_3 - (uint)*(ushort *)(param_1 + 300)) - *(int *)(param_1 + 0x120)) + -1;
  if (-iVar1 < iVar3) {
    iVar3 = iVar1;
  }
  iVar1 = (((uint)(ushort)param_3[3] + (int)param_3[1] + param_2) - *(int *)(param_1 + 0x128)) + 1;
  iVar2 = ((param_3[1] - param_2) - *(int *)(param_1 + 0x128)) + -1;
  if (-iVar2 < iVar1) {
    iVar1 = iVar2;
  }
  FUN_80067028(param_1,param_1 + 0x1b4,iVar3,iVar1);
  return;
}
