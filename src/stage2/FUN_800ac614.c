/* FUN_800ac614
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac614  body 0x800ac614..0x800ac69b  size 136 B
 * body sha256 c1069e7ba7b48d5a77fc62dd137a24eec51480798ba90d1ad293c8355116fccd
 * provider record sha256 0311fff5fb4ee2dc204491537eae460c06cabbc36e0e3de8b46fbfbd8dfd5170
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ac614(uint param_1,uint param_2,uint param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  
  if ((param_3 & 0xff) == 0xff) {
    iVar2 = -0x7feb3080;
    param_1 = param_1 & 0xff;
    iVar1 = (param_2 & 0xff) * 0x86;
  }
  else {
    iVar2 = -0x7feb7380;
    param_1 = (param_1 & 0xff) + (param_2 & 0xff) * 0x86;
    iVar1 = (param_3 & 0xff) * 0x860;
  }
  *(byte *)(param_1 + iVar1 + iVar2) = param_4 & 0x7f;
  return;
}
