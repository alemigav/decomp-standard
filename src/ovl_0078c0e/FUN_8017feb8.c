/* FUN_8017feb8
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017feb8  body 0x8017feb8..0x8017ff0b  size 84 B
 * body sha256 d3f6c51290d52d65384054de6c9c65997e6dbe3d267dd13527e712cddc38a67d
 * provider record sha256 28a33b7aeb1db172a5b7fe509f21e502d35945d46f9b69a0a02c861d11539169
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8017feb8(char param_1)

{
  uint uVar1;
  undefined2 local_10;
  char cStack_e;
  undefined1 uStack_d;
  undefined1 local_c;
  undefined1 local_b;
  
  local_c = 0x3a;
  local_b = 0;
  _local_10 = CONCAT22(0x6275,CONCAT11(param_1 + '0',0x30));
  uVar1 = FUN_8017ff80(&local_10);
  return uVar1 ^ 1;
}
