/* FUN_800283f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800283f0  body 0x800283f0..0x8002841b  size 44 B
 * body sha256 6261e3f0d3d4bd2be1162d47a7fa9f1d667ed4a5088debb5565be7b6911979a9
 * provider record sha256 80d089e3f4440a9211f43d8af308f1a9e4609ee28270a1bb63c280afad439da9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800283f0(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x84);
  *(undefined4 *)(iVar1 + 0x80) = 0;
  return;
}
