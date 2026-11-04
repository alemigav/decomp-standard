/* FUN_801655d8
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x801655d8  body 0x801655d8..0x801656ab  size 212 B
 * body sha256 0f05213b39889bee15ed735dc0fcfbca2fc8476c9c2fea56235b1028b0dc3749
 * provider record sha256 de3601d5214a79d30895e6e5d360dc4df42bd9c242a3dbdf139c800be0e42959
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801655d8(uint *param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      goto LAB_80165670;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x9c) = 0;
    param_1[4] = param_1[4] | 0x80;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    func_0x80036c68(param_1,0,0,0);
    *param_1 = *param_1 | 8;
  }
  if (*(short *)(param_1 + 0x9c) == 0) {
    return;
  }
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
LAB_80165670:
  func_0x80036c68(param_1,0,0,0);
  if (*(short *)(param_1 + 0x9c) == 2) {
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  return;
}
