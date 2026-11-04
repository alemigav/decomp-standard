/* FUN_801646e4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801646e4  body 0x801646e4..0x8016472b  size 72 B
 * body sha256 f54ee5140e031d5c0a469cc489d98b8b5d103a8319e564db5750c6cf3e4fa19b
 * provider record sha256 5c830d1a9e87e373137177732316d977949c5d13fd1250123f24651a9758257f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801646e4(int param_1)

{
  (*(code *)(&PTR_FUN_80166de4)[*(byte *)(param_1 + 6)])();
  FUN_801664d8(param_1);
  return;
}
