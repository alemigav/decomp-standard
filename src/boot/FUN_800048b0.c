/* FUN_800048b0
 * image   boot (boot), base 0x80000480
 * address 0x800048b0  body 0x800048b0..0x800048df  size 48 B
 * body sha256 bd3ca2d443199f2706dab5b1172683c80caa79e572d9274f89a6da95ce3b53de
 * provider record sha256 ac00d0b6fb163725f1eab95132420ea686a12e842a8fa8d2f72ca555612346b7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800048b0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x8000 - *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x10) = 0x8000;
    iVar1 = *(int *)(param_1 + 0x50) + iVar2;
    *(int *)(param_1 + 0x50) = iVar1;
    *(int *)(param_1 + 0xc) = iVar1;
  }
  return iVar2;
}
