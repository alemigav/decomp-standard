/* FUN_80135cb0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80135cb0  body 0x80135cb0..0x80135ccb  size 28 B
 * body sha256 1b1683be0349dbf04bddbc165e45e30d3e07d3f980df4db6edafb93613c26d4a
 * provider record sha256 5ac7651db84080c9cd4878b9d3863e6961f09276206ef872da3be0d176337393
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80135cb0(uint param_1,uint param_2)

{
  uint uVar1;
  
  do {
    uVar1 = param_1 + 0x10;
    cacheOp(0xd,param_1);
    param_1 = uVar1;
  } while (uVar1 < param_2);
  return;
}
