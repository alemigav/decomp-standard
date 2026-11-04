/* FUN_8009d7e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d7e4  body 0x8009d7e4..0x8009d827  size 68 B
 * body sha256 eef98db18a4a0b6f8f44ea9779d51ec2f59b1cdc843842787822a97c63ae798f
 * provider record sha256 d9542eb5e5631af03676266f96014779ca6234c05b9e304317df3f3e0d26aa54
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009d7e4(void)

{
  if ((DAT_800e10ec & 0x200) == 0) {
    FUN_8006c070(1);
    DAT_8013272e = 10;
    DAT_8013273a = 0;
  }
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
