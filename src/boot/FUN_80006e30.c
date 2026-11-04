/* FUN_80006e30
 * image   boot (boot), base 0x80000480
 * address 0x80006e30  body 0x80006e30..0x80006efb  size 204 B
 * body sha256 b1e0a2ea06e182f5d05c98962ebef8739ec06ba8ac6697657b352ac8b4435ec6
 * provider record sha256 d58feb18632e8129999150c4d8ce7b20b090adf74cb762de5282e7188f6eba7d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80006e30(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = FUN_800072e0();
  if (param_1 == 0) {
    param_1 = _DAT_80012950;
  }
  else if (*(short *)(param_1 + 0x10) != 1) {
    FUN_8000ded0(*(undefined4 *)(param_1 + 8),param_1);
  }
  if (_DAT_8001294c == param_1) {
    _DAT_8001294c = *(int *)(param_1 + 0xc);
  }
  else {
    iVar3 = *(int *)(_DAT_8001294c + 0xc);
    iVar2 = _DAT_8001294c;
    while (iVar1 = iVar3, iVar1 != 0) {
      if (iVar1 == param_1) {
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 0xc);
        break;
      }
      iVar2 = iVar1;
      iVar3 = *(int *)(iVar1 + 0xc);
    }
  }
  if (param_1 == _DAT_80012950) {
    FUN_80000f60();
  }
  FUN_80007300(uVar4);
  return;
}
