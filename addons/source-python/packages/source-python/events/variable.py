# ../events/variable.py

"""Provides variable types to be used with custom events."""

# =============================================================================
# >> IMPORTS
# =============================================================================
# Source.Python Imports
#   Events
from events import events_logger


# =============================================================================
# >> ALL DECLARATION
# =============================================================================
__all__ = ('BoolVariable',
           'ByteVariable',
           'FloatVariable',
           'LongVariable',
           'ShortVariable',
           'StringVariable',
           )


# =============================================================================
# >> GLOBAL VARIABLES
# =============================================================================
# Store a dictionary to get default values
_DEFAULT_VALUES = {'bool': bool, 'int': int, 'float': float, 'string': str}

# Get the sp.events.variable logger
events_variable_logger = events_logger.variable


# =============================================================================
# >> CLASSES
# =============================================================================
class _EventVariable(object):

    """Base class used for event variable types."""

    def __init__(self, comment='', default=None):
        """Called on instantiation."""
        # Was a default value passed?
        if default is not None:

            # Set the default value
            self._default = default

        # Was no default value passed?
        else:

            # Set the default value to the type's default
            self._default = _DEFAULT_VALUES[self._method]()

        # Store the comment
        self._comment = comment

    @property
    def name(self):
        """Return the variable type name."""
        return self.__class__.__name__.lower().replace('variable', '')


class BoolVariable(_EventVariable):

    """Class used to store bool event variables."""

    _method = 'bool'


class ByteVariable(_EventVariable):

    """Class used to store byte event variables."""

    _method = 'int'


class ShortVariable(_EventVariable):

    """Class used to store short event variables."""

    _method = 'int'


class LongVariable(_EventVariable):

    """Class used to store long event variables."""

    _method = 'int'


class FloatVariable(_EventVariable):

    """Class used to store floating point event variables."""

    _method = 'float'


class StringVariable(_EventVariable):

    """Class used to store string event variables."""

    _method = 'string'
