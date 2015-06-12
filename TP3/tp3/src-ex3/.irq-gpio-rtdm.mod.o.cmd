cmd_/home/quentin/Git/MI11-OS/TP3/tp3/src-ex3/irq-gpio-rtdm.mod.o := arm-buildroot-linux-uclibcgnueabi-gcc -Wp,-MD,/home/quentin/Git/MI11-OS/TP3/tp3/src-ex3/.irq-gpio-rtdm.mod.o.d  -nostdinc -isystem /opt/armadeus/buildroot/output/host/usr/lib/gcc/arm-buildroot-linux-uclibcgnueabi/4.7.3/include -Iinclude  -I/opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include -include include/linux/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-imx/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Os -marm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -msoft-float -Uarm -Wframe-larger-than=1024 -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -Wdeclaration-after-statement -Wno-pointer-sign -fwrapv -fno-dwarf2-cfi-asm -g -W -Wall -I /opt/armadeus/buildroot/output/build/linux-headers-2.6.29.6/ -I/opt/armadeus/buildroot/output/staging/usr/include/xenomai/ -D_GNU_SOURCE -D_REENTRANT  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(irq_gpio_rtdm.mod)"  -D"KBUILD_MODNAME=KBUILD_STR(irq_gpio_rtdm)"  -DMODULE -c -o /home/quentin/Git/MI11-OS/TP3/tp3/src-ex3/irq-gpio-rtdm.mod.o /home/quentin/Git/MI11-OS/TP3/tp3/src-ex3/irq-gpio-rtdm.mod.c

deps_/home/quentin/Git/MI11-OS/TP3/tp3/src-ex3/irq-gpio-rtdm.mod.o := \
  /home/quentin/Git/MI11-OS/TP3/tp3/src-ex3/irq-gpio-rtdm.mod.c \
    $(wildcard include/config/module/unload.h) \
  include/linux/module.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/markers.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/sysfs.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  include/linux/poison.h \
  include/linux/prefetch.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbd.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  include/linux/posix_types.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/posix_types.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/processor.h \
    $(wildcard include/config/arm/fcse.h) \
    $(wildcard include/config/mmu.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/arm/thumb.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/hwcap.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/cache.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/system.h \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/ipipe/want/preemptible/switch.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
  include/linux/linkage.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/linkage.h \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
    $(wildcard include/config/x86.h) \
  include/linux/typecheck.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/irqflags.h \
    $(wildcard include/config/ipipe.h) \
    $(wildcard include/config/ipipe/trace/irqsoff.h) \
  include/asm-generic/cmpxchg-local.h \
  include/asm-generic/cmpxchg.h \
  include/linux/stat.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/stat.h \
  include/linux/time.h \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/printk/debug.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /opt/armadeus/buildroot/output/host/usr/lib/gcc/arm-buildroot-linux-uclibcgnueabi/4.7.3/include/stdarg.h \
  include/linux/bitops.h \
    $(wildcard include/config/generic/find/first/bit.h) \
    $(wildcard include/config/generic/find/last/bit.h) \
    $(wildcard include/config/generic/find/next/bit.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/bitops.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/ffz.h \
  include/asm-generic/bitops/__fls.h \
  include/asm-generic/bitops/__ffs.h \
  include/asm-generic/bitops/fls.h \
  include/asm-generic/bitops/ffs.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/lock.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/ipipe_base.h \
    $(wildcard include/config/ipipe/debug/context.h) \
    $(wildcard include/config/generic/clockevents.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/ipipe_base.h \
    $(wildcard include/config/vfp.h) \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/irq.h \
  arch/arm/mach-imx/include/mach/irqs.h \
  arch/arm/mach-imx/include/mach/hardware.h \
    $(wildcard include/config/arch/mx1ads.h) \
    $(wildcard include/config/mach/apf9328.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/sizes.h \
  arch/arm/mach-imx/include/mach/imx-regs.h \
  arch/arm/mach-imx/include/mach/apf9328.h \
    $(wildcard include/config/imx/apf9328/flash/8mb.h) \
    $(wildcard include/config/imx/apf9328/flash/16mb.h) \
  include/linux/ratelimit.h \
  include/linux/param.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/param.h \
    $(wildcard include/config/hz.h) \
  include/linux/dynamic_printk.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/iwmmxt.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
  include/linux/stringify.h \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  include/linux/spinlock_types_up.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/generic/hardirqs.h) \
  include/linux/spinlock_up.h \
  include/linux/spinlock_api_up.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/atomic.h \
  include/asm-generic/atomic.h \
  include/linux/math64.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/div64.h \
  include/linux/kmod.h \
  include/linux/gfp.h \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/highmem.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/unevictable/lru.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/arch/populates/node/map.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
  include/linux/wait.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/current.h \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/init.h \
    $(wildcard include/config/hotplug.h) \
  include/linux/nodemask.h \
  include/linux/bitmap.h \
  include/linux/string.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/string.h \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/linux/bounds.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v3.h) \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
    $(wildcard include/config/aeabi.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/glue.h \
    $(wildcard include/config/cpu/arm610.h) \
    $(wildcard include/config/cpu/arm710.h) \
    $(wildcard include/config/cpu/abrt/lv4t.h) \
    $(wildcard include/config/cpu/abrt/ev4.h) \
    $(wildcard include/config/cpu/abrt/ev4t.h) \
    $(wildcard include/config/cpu/abrt/ev5tj.h) \
    $(wildcard include/config/cpu/abrt/ev5t.h) \
    $(wildcard include/config/cpu/abrt/ev6.h) \
    $(wildcard include/config/cpu/abrt/ev7.h) \
    $(wildcard include/config/cpu/pabrt/ifar.h) \
    $(wildcard include/config/cpu/pabrt/noifar.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/memory.h \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
  include/linux/const.h \
  arch/arm/mach-imx/include/mach/memory.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/sparsemem/vmemmap.h) \
  include/asm-generic/page.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/memory/hotremove.h) \
  include/linux/notifier.h \
  include/linux/errno.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/linux/rwsem-spinlock.h \
  include/linux/srcu.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
  include/linux/cpumask.h \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/topology.h \
  include/asm-generic/topology.h \
  include/linux/elf.h \
  include/linux/elf-em.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/elf.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/user.h \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/kref.h \
  include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  include/linux/marker.h \
  include/linux/tracepoint.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/classic/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/preempt/rcu.h) \
  include/linux/percpu.h \
  include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/debug/slab.h) \
  include/linux/slab_def.h \
  include/linux/kmalloc_sizes.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/percpu.h \
  include/asm-generic/percpu.h \
    $(wildcard include/config/ipipe/debug.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/completion.h \
  include/linux/rcuclassic.h \
    $(wildcard include/config/rcu/cpu/stall/detector.h) \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/local.h \
  include/asm-generic/local.h \
  /opt/armadeus/buildroot/output/build/linux-2.6.29.6/arch/arm/include/asm/module.h \
  include/linux/vermagic.h \
  include/linux/utsrelease.h \

/home/quentin/Git/MI11-OS/TP3/tp3/src-ex3/irq-gpio-rtdm.mod.o: $(deps_/home/quentin/Git/MI11-OS/TP3/tp3/src-ex3/irq-gpio-rtdm.mod.o)

$(deps_/home/quentin/Git/MI11-OS/TP3/tp3/src-ex3/irq-gpio-rtdm.mod.o):
