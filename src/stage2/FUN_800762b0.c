/* FUN_800762b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800762b0  body 0x800762b0..0x80076313  size 100 B
 * body sha256 9c89ca3ccafccd6848602617f835aaa2b6267ac46662acab544a4879889d5f02
 * provider record sha256 933b9e137221a13021dff570808f39bf38d5e157bc5cfe62ec03f95269708685
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800762b0(void)

{
  DAT_80119e28 = 1;
  DAT_8011a718 = *(undefined4 *)((&PTR_PTR_80119e20)[DAT_800e110c < 0] + DAT_800e8ca8 * 4 + 4);
  return;
}
