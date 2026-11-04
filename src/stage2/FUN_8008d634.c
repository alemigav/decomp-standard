/* FUN_8008d634
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d634  body 0x8008d634..0x8008d6b3  size 128 B
 * body sha256 de69e9d09a79a6cc71b59136bcbc21f9fb604a1fa30f267e259127f04d96824d
 * provider record sha256 2f2f1c5a1b5e76c73d28873053645bc544ca8d19115f6c55b9bd5812cac87c27
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008d634(void)

{
  undefined4 uVar1;
  
  FUN_80043620();
  FUN_80096d90();
  FUN_800978a4();
  FUN_80097c4c();
  uVar1 = FUN_8008c3a0();
  FUN_800981d8(uVar1);
  FUN_800969a4();
  FUN_80097174();
  FUN_80095c34();
  (*(code *)(&PTR_FUN_8012f914)[DAT_8012bf99])();
  return;
}
