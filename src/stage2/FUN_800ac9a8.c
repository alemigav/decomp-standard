/* FUN_800ac9a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac9a8  body 0x800ac9a8..0x800ac9d3  size 44 B
 * body sha256 0a5cb9f0020534cadd3caccf65f09aae09b3a224f14f47941eed5d668db97a30
 * provider record sha256 4a2c03b50231b5c3d8ccff1f0fa0e26eb36de197bdeaf71b5442c811eb4797d3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined1 FUN_800ac9a8(undefined1 param_1)

{
  switch(param_1) {
  case 0x80:
    param_1 = 0x80;
    break;
  case 0x81:
    param_1 = 0x82;
    break;
  case 0x82:
    param_1 = 0xa0;
    break;
  case 0x83:
    param_1 = 0xa1;
    break;
  case 0x84:
    param_1 = 0x83;
    break;
  case 0x85:
    param_1 = 0x84;
  }
  return param_1;
}
