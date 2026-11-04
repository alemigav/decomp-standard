/* overlay_open
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cc5c  body 0x8004cc5c..0x8004cca7  size 76 B
 * body sha256 f1b0104751bf8d920b784d4d5a655fc06ae56e7cb13bf8a9f0ebe3f153b3bb87
 * provider record sha256 b8e69da80e8a1f171bff07fef88bd603d26164bc149794c5d1885cd70606b0f8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void overlay_open(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = cart_record((&DAT_8010b2e0)[param_1 * 8]);
  overlay_inflate(uVar1);
  (**(code **)(&DAT_8010b2e4 + param_1 * 8))();
  return;
}
