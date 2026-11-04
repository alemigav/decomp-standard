/* FUN_80091784
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091784  body 0x80091784..0x800917f3  size 112 B
 * body sha256 e3ef88c4ae0a86156de17917960303de23dacde7dcbc9c383f284ae995326cfe
 * provider record sha256 7131238946d6a29b061875eff3c3b0f9cff606eb8ebc655b8a9d024357e08922
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8009177c::caseD_0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint unaff_s0;
  
  if (((unaff_s0 == 0x11) || (unaff_s0 == 0x17)) || ((unaff_s0 == 0x12 && (param_2 == 3)))) {
    uVar1 = 4;
  }
  else {
    uVar1 = 0;
    if ((((3 < unaff_s0) && (uVar1 = 1, 7 < unaff_s0)) && (uVar1 = 3, 0x15 < unaff_s0)) &&
       ((uVar1 = 0, unaff_s0 == 0x16 && (uVar1 = 3, param_2 != 4)))) {
      uVar1 = 2;
    }
  }
  return uVar1;
}
