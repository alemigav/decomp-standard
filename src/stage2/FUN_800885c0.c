/* FUN_800885c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800885c0  body 0x800885c0..0x80088667  size 168 B
 * body sha256 9baab748f96742ab12d0e5b8fa86a133de7cfc35d9fdef5da7110453d5f61304
 * provider record sha256 da667530be5399a0dce58d845d58eb74d60393ce03ddae1b5bb652b1d944bca6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800885c0(void)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  
  bVar1 = DAT_8012bcb4 < DAT_8012bcb2;
  uVar2 = DAT_8012bcb4 + 1;
  if (bVar1) {
    iVar3 = (uint)uVar2 * 0xc + DAT_8012bcb8;
    DAT_8012bcb4 = uVar2;
    func_0x8000bd80(0x8013a350,0,0,*(undefined4 *)(iVar3 + -8),*(undefined4 *)(iVar3 + -4),
                    *(undefined4 *)((uint)uVar2 * 0xc + DAT_8012bcb8 + -0xc),&DAT_8012bd30);
  }
  return bVar1;
}
