/* FUN_80085300
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80085300  body 0x80085300..0x80085397  size 152 B
 * body sha256 ca5f8f8a7236a3107e7da557d66e5418448f401c4b3f2c410949afb1111981bb
 * provider record sha256 cb62703b05055357145e37930d8beae6ed63ced9ac3cf2203e7d6e51249ea861
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80085300(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x7f;
  if ((&DAT_8012487c)[uVar2 * 4] == param_1) {
    (&DAT_8012486c)[uVar2 >> 5] =
         (&DAT_8012486c)[uVar2 >> 5] & ~(1 << ((&DAT_8012487c)[uVar2 * 4] & 0x1f));
    uVar1 = func_0x800072e0();
    (&DAT_80124880)[uVar2 * 4] = DAT_8012485c;
    DAT_80124868 = DAT_80124868 + -1;
    DAT_8012485c = uVar2;
    func_0x80007300(uVar1);
  }
  return;
}
