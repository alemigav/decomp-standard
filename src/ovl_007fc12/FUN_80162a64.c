/* FUN_80162a64
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162a64  body 0x80162a64..0x80162adf  size 124 B
 * body sha256 5a9b95c9c3779840bcce2490ad031f26e8ec3ccd41a77200f03fd8999b60cf06
 * provider record sha256 f30d7a626cd0c09e019e58e494ad191727f88cc8a19c99350e0960e44bf9fdfa
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162a64(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8016e1ac)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8016e1ec)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
