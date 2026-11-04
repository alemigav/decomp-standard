/* FUN_8009d774
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d774  body 0x8009d774..0x8009d7ab  size 56 B
 * body sha256 b36b9ec6787f52878d9a8dfe1cc30128c79aadec24e1b7749ba62bcc5df43b6d
 * provider record sha256 cb8e5f995dc58f4c4027ddba7859318ff31a508dc6996932614660175129ec30
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d774(void)

{
  if ((DAT_800e10ec & 0x200) == 0) {
    FUN_8006c070(1);
    DAT_8013272e = 8;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
